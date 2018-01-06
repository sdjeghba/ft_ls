/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:04:18 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/06 15:27:32 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		deal_with_dirs(t_flags *flag, char *dir_name)
{
	t_data	data;
	t_info	*info;

	info = NULL;
	data.f_name = NULL;
	data.abs_path = NULL;
	if (flag->args_nbr > 1)
	{
		ft_putstr(dir_name);
		ft_putstr(":\n");
	}
	if (flag->upp_r == 1)
		do_recursion(dir_name, flag);
	else
	{
		if (!(data.dir = opendir(dir_name)))
			display_dir_error(dir_name);
		else
		{
			all_in_one_info(dir_name, &info, &data, flag);
			free_info(&info);
		}
		if (data.dir)
			closedir(data.dir);
	}
}

int			core_program(t_info *files, t_info *dir, t_flags *flag)
{
	if (!(files) && !(dir) && !(flag->err))
		flag->upp_r == 1 ? do_recursion(".", flag) : deal_with_dirs(flag, ".");
	else
	{
		if (flag->upp_r == 1)
			recursive(files, dir, flag);
		else
		{
			sort_list(&files, flag);
			flag->l ? display_list(files, flag) : display_files(files, flag);
			sort_list(&dir, flag);
			files && dir ? ft_putchar('\n') : 0;
			while (dir)
			{
				deal_with_dirs(flag, dir->d_name);
				dir->next ? ft_putchar('\n') : 0;
				dir = dir->next;
			}
		}
	}
	return (0);
}

int			get_args(t_list *list, t_info **files, t_info **dir, t_flags *flag)
{
	t_data	data;

	data.f_name = NULL;
	data.abs_path = NULL;
	lstat((char *)list->content, &data.stat);
	if (S_ISLNK(data.stat.st_mode) && flag->l == 0)
		stat((char *)list->content, &data.stat);
	if (get_argmode(&data))
	{
		data.getpwuid = getpwuid(data.stat.st_uid);
		data.group = getgrgid(data.stat.st_gid);
		data.f_name = ft_strdup((char *)list->content);
		S_ISDIR(data.stat.st_mode) ? lstaddend(dir, &data) :
			lstaddend(files, &data);
		ft_strlen(data.f_name) ? ft_strdel(&data.f_name) : 0;
	}
	else
	{
		no_file_or_directory((char *)list->content);
		flag->err = 1;
	}
	data.stat.st_mode = -1;
	return (0);
}

int			get_and_check_args(char **av, int *i, int ac, t_args *args)
{
	t_list *tmp;

	args->list = NULL;
	args->files = NULL;
	args->dir = NULL;
	while (av[*i] && *i < ac)
		ft_lstpushback(av[(*i)], ft_strlen(av[(*i)++]) + 1, &args->list);
	tmp = args->list;
	if (args->list && ft_strcmp("--", (char *)args->list->content) == 0
			&& ft_lstlen(&args->list) == 1)
	{
		deal_with_dirs(&args->flag, ".");
		return (1);
	}
	else if (args->list && ft_strcmp("--", (char *)args->list->content)
			== 0 && ft_lstlen(&args->list) > 1)
		tmp = tmp->next;
	ft_lstsortbyname(&(args->list));
	args->flag.args_nbr = ft_lstlen(&args->list);
	while (tmp)
	{
		get_args(tmp, &args->files, &args->dir, &args->flag);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_ls(int ac, char **av)
{
	t_args	args;
	int		i;

	i = 0;
	args.flag = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	args.list = NULL;
	if (ac == 1)
		deal_with_dirs(&args.flag, ".");
	else
	{
		check_flags(av, ac, &i, &args.flag);
		if (!(get_and_check_args(av, &i, ac, &args)))
			core_program(args.files, args.dir, &args.flag);
		args.list ? free_list(&args.list) : 0;
	}
	return (0);
}
