/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 18:38:11 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/04 04:39:32 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_hiddir(t_info *info, t_flags *flag, char *dir_n)
{
	char	*path;

	path = NULL;
	if (info->rights[0] != 'd' || (ft_strcmp(info->d_name, ".") == 0) ||
					ft_strcmp(info->d_name, "..") == 0)
		return (0);
	if (flag->a == 1)
	{
		ft_putchar('\n');
		path = ft_place_between_str(dir_n, info->d_name, "/");
		do_recursion(path, flag);
		path ? ft_strdel(&path) : 0;
	}
	else
	{
		if (info->d_name[0] != '.')
		{
			ft_putchar('\n');
			path = ft_place_between_str(dir_n, info->d_name, "/");
			do_recursion(path, flag);
			path ? ft_strdel(&path) : 0;
		}
	}
	return (0);
}

void		do_recursion(char *dir_name, t_flags *flag)
{
	t_info	*info;
	t_info	*tmp;
	t_data	data;

	info = NULL;
	tmp = NULL;
	data.f_name = NULL;
	data.abs_path = NULL;
	if (!(ft_strstr(".", dir_name)) && flag->frst != 1)
		ft_putdblstr(dir_name, ":\n");
	flag->frst = 0;
	if (!(data.dir = opendir(dir_name)))
		display_dir_error((char *)dir_name);
	else
	{
		all_in_one_info((char *)dir_name, &info, &data, flag);
		tmp = info;
		while (info)
		{
			check_hiddir(info, flag, (char *)dir_name);
			info = info->next;
		}
		tmp ? free_info(&tmp) : 0;
		closedir(data.dir);
	}
}

int			recursive(t_info *files, t_info *dir, t_flags *flag)
{
	flag->frst = (flag->args_nbr < 2 ? 1 : 0);
	flag->l == 1 ? display_list(files, flag) : display_files(files, flag);
	while (dir)
	{
		do_recursion(dir->d_name, flag);
		if (dir->next)
			ft_putchar('\n');
		flag->frst = 0;
		dir = dir->next;
	}
	return (0);
}
