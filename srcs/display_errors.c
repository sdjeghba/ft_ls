/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:01:34 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/06 15:13:13 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		display_dir_error(char *dir_name)
{
	ft_putstr("ls :");
	ft_putdblstr(dir_name, ": ");
	perror("");
}

void		no_file_or_directory(char *str)
{
	ft_putstr("ls: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}

void		illegal_option(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-RalrtpGT1mo] [file ...]");
	exit(0);
}

void		free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*now;

	tmp = *list;
	now = *list;
	while (now->next)
	{
		tmp = now->next;
		ft_strlen((char*)now->content) ? ft_strdel((char**)&now->content) : 0;
		now->content_size = 0;
		now = tmp;
	}
}

void		free_info(t_info **info)
{
	t_info	*tmp;
	t_info	*now;

	tmp = *info;
	now = *info;
	while (now)
	{
		tmp = now->next;
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
		ft_strlen(now->path) ? ft_strdel(&now->path) : 0;
		now->d_date ? ft_free_tab(now->d_date) : 0;
		now->d_date ? free(now->d_date) : 0;
		free(now);
		now = tmp;
	}
}
