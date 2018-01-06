/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:46:12 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/04 05:30:34 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		swap_values(t_info *dest, t_info *src)
{
	dest->d_name = ft_strdup(src->d_name);
	dest->d_type = src->d_type;
	dest->st_size = ft_strdup(src->st_size);
	dest->mtime = src->mtime;
	dest->st_nlink = ft_strdup(src->st_nlink);
	dest->st_blocks = src->st_blocks;
	dest->pw_name = ft_strdup(src->pw_name);
	dest->gr_name = ft_strdup(src->gr_name);
	dest->m_date = ft_strdup(src->m_date);
	dest->d_date = ft_copy_tab(src->d_date);
	dest->rights = ft_strdup(src->rights);
	dest->path = ft_strdup(src->path);
}

void		reverse_list(t_info **list)
{
	t_info	*p;
	t_info	*q;
	t_info	*r;

	p = *list;
	q = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*list = q;
	q = NULL;
	r = NULL;
	p = NULL;
}

void		sort_list_by_time(t_info **info)
{
	int		i;
	t_info	*tmp;
	t_info	swap;
	int		size_list;

	i = 0;
	size_list = lstlen(*info);
	while (i++ < size_list)
	{
		tmp = *info;
		while (tmp->next)
		{
			if (tmp->mtime < tmp->next->mtime)
			{
				swap_values(&swap, tmp->next);
				free_values(tmp->next);
				swap_values(tmp->next, tmp);
				free_values(tmp);
				swap_values(tmp, &swap);
				free_values(&swap);
			}
			tmp = tmp->next;
		}
	}
}

void		sort_list_by_name(t_info **info, int size_list)
{
	int		i;
	t_info	*tmp;
	t_info	swap;

	i = 0;
	tmp = *info;
	while (i++ < size_list)
	{
		tmp = *info;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->d_name, tmp->next->d_name) > 0)
			{
				swap_values(&swap, tmp->next);
				free_values(tmp->next);
				swap_values(tmp->next, tmp);
				free_values(tmp);
				swap_values(tmp, &swap);
				free_values(&swap);
			}
			tmp = tmp->next;
		}
	}
}

void		sort_list(t_info **info, t_flags *flag)
{
	int		size_list;

	size_list = lstlen(*info);
	sort_list_by_name(info, size_list);
	flag->t == 1 ? sort_list_by_time(info) : 0;
	flag->r == 1 ? reverse_list(info) : 0;
}
