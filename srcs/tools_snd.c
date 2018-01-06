/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_snd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 04:28:32 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/01/06 15:28:17 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		put_color(char c)
{
	c == 'c' ? ft_putstr(YELLOW) : 0;
	c == 'd' ? ft_putstr(BOLD) : 0;
	c == 'l' ? ft_putstr(ROSE) : 0;
	c == 's' ? ft_putstr(RED) : 0;
	c == 'b' ? ft_putstr(CYAN) : 0;
	c == 'p' ? ft_putstr(GREEN) : 0;
}

void		free_values(t_info *now)
{
	ft_strlen(now->d_name) ? ft_strdel(&now->d_name) : 0;
	now->d_type = 0;
	ft_strlen(now->st_size) ? ft_strdel(&now->st_size) : 0;
	now->mtime = 0;
	ft_strlen(now->st_nlink) ? ft_strdel(&now->st_nlink) : 0;
	now->st_blocks = 0;
	ft_strlen(now->pw_name) ? ft_strdel(&now->pw_name) : 0;
	ft_strlen(now->gr_name) ? ft_strdel(&now->gr_name) : 0;
	ft_strlen(now->rights) ? ft_strdel(&now->rights) : 0;
	ft_strlen(now->m_date) ? ft_strdel(&now->m_date) : 0;
	now->d_date ? ft_free_tab(now->d_date) : 0;
	now->d_date ? free(now->d_date) : 0;
	ft_strlen(now->path) ? ft_strdel(&now->path) : 0;
}

int			get_min_maj(t_data *data, t_info *new)
{
	char *major;
	char *minor;

	major = ft_itoa(major(data->stat.st_rdev));
	minor = ft_itoa(minor(data->stat.st_rdev));
	new->st_size = ft_strnew(ft_strlen(major) + ft_strlen(minor) + 2);
	ft_strcpy(new->st_size, major);
	ft_strcat(new->st_size, ", ");
	ft_strcat(new->st_size, minor);
	major ? ft_strdel(&major) : 0;
	minor ? ft_strdel(&minor) : 0;
	return (0);
}

void		check_acl(char *path)
{
	int		xattrs;
	acl_t	acl;

	xattrs = (int)listxattr(path, NULL, 1, XATTR_NOFOLLOW);
	if (xattrs > 0)
		ft_putchar('@');
	else
	{
		acl = acl_get_file(path, ACL_TYPE_EXTENDED);
		acl ? ft_putchar('+') : 0;
		!acl ? ft_putchar(' ') : 0;
		acl ? free(acl) : 0;
	}
	ft_putchar(' ');
}

int			get_argmode(t_data *data)
{
	int		i;

	i = 0;
	if ((S_ISLNK(data->stat.st_mode)) || (S_ISREG(data->stat.st_mode)) ||
			(S_ISDIR(data->stat.st_mode)) || (S_ISCHR(data->stat.st_mode)) ||
			(S_ISBLK(data->stat.st_mode)) || (S_ISFIFO(data->stat.st_mode)) ||
			(S_ISSOCK(data->stat.st_mode)))
		i++;
	return (i);
}
