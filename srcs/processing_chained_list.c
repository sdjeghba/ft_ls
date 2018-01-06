/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_chained_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:35:31 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/05 19:47:34 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_rights(t_data *data)
{
	char	*rights;

	rights = ft_strnew(11);
	(rights[0] = (S_ISDIR(data->stat.st_mode)) ? 'd' : '-');
	(rights[0] = (S_ISLNK(data->stat.st_mode)) ? 'l' : rights[0]);
	(rights[0] = (S_ISSOCK(data->stat.st_mode)) ? 's' : rights[0]);
	(rights[0] = (S_ISFIFO(data->stat.st_mode)) ? 'p' : rights[0]);
	(rights[0] = (S_ISCHR(data->stat.st_mode)) ? 'c' : rights[0]);
	(rights[0] = (S_ISBLK(data->stat.st_mode)) ? 'b' : rights[0]);
	(rights[1] = (data->stat.st_mode & S_IRUSR) ? 'r' : '-');
	(rights[2] = (data->stat.st_mode & S_IWUSR) ? 'w' : '-');
	(rights[3] = (data->stat.st_mode & S_IXUSR) ? 'x' : '-');
	(rights[4] = (data->stat.st_mode & S_IRGRP) ? 'r' : '-');
	(rights[5] = (data->stat.st_mode & S_IWGRP) ? 'w' : '-');
	(rights[6] = (data->stat.st_mode & S_IXGRP) ? 'x' : '-');
	(rights[7] = (data->stat.st_mode & S_IROTH) ? 'r' : '-');
	(rights[8] = (data->stat.st_mode & S_IWOTH) ? 'w' : '-');
	(rights[9] = (data->stat.st_mode & S_IXOTH) ? 'x' : '-');
	if (S_ISUID & data->stat.st_mode)
		rights[3] = (rights[3] == '-' ? 'S' : 's');
	if (S_ISGID & data->stat.st_mode)
		rights[6] = (rights[6] == '-' ? 'S' : 's');
	if (S_ISVTX & data->stat.st_mode)
		rights[9] = (rights[9] == '-' ? 'T' : 't');
	return (rights);
}

int			lstlen(t_info *info)
{
	t_info	*tmp;
	int		i;

	i = 0;
	tmp = info;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_info		*addelem(t_data *data)
{
	t_info	*new;

	if (!(new = malloc(sizeof(t_info))))
		return (NULL);
	new->d_name = (data->f_name ? ft_strdup(data->f_name) :
			ft_strdup(data->file->d_name));
	new->d_type = data->file->d_type;
	new->rights = get_rights(data);
	if (new->rights[0] == 'b' || new->rights[0] == 'c')
		get_min_maj(data, new);
	else
		new->st_size = ft_itoa(data->stat.st_size);
	new->mtime = data->stat.st_mtime;
	new->st_nlink = ft_itoa(data->stat.st_nlink);
	new->st_blocks = data->stat.st_blocks;
	new->pw_name = (data->getpwuid ? ft_strdup(data->getpwuid->pw_name) :
			ft_itoa(data->stat.st_uid));
	new->gr_name = (data->group ? ft_strdup(data->group->gr_name) :
			ft_itoa(data->stat.st_gid));
	new->m_date = ft_strdup(ctime(&(new->mtime)));
	new->d_date = ft_strsplit(new->m_date, ' ');
	new->path = (data->abs_path ? data->abs_path : new->d_name);
	new->next = NULL;
	return (new);
}

void		lstaddend(t_info **info, t_data *data)
{
	t_info *tmp;

	tmp = *info;
	if (tmp == NULL)
		*info = addelem(data);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = addelem(data);
	}
}

int			all_in_one_info(char *p, t_info **info, t_data *data, t_flags *flag)
{
	char	*tmp;

	tmp = NULL;
	while ((data->file = readdir(data->dir)))
	{
		tmp = ft_place_between_str(p, data->file->d_name, "/");
		lstat(tmp, &data->stat);
		data->getpwuid = getpwuid(data->stat.st_uid);
		data->group = getgrgid(data->stat.st_gid);
		data->abs_path = (tmp ? ft_strdup(tmp) : NULL);
		lstaddend(info, data);
		ft_strlen(tmp) ? ft_memdel((void**)&tmp) : 0;
	}
	sort_list(info, flag);
	if (data->file && !flag->upp_r)
	{
		ft_putstr(p);
		ft_putstr(":\n");
	}
	flag->l == 1 ? display_list(*info, flag) : display_files(*info, flag);
	return (0);
}
