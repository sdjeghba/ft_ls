/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:11:54 by salemdje          #+#    #+#             */
/*   Updated: 2017/12/14 11:40:16 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			f_wordtab(int *word, t_info *tmp)
{
	int		lgst;

	lgst = 0;
	if ((lgst = (ft_strlen(tmp->st_nlink))) > word[0])
		word[0] = lgst;
	if ((lgst = (ft_strlen(tmp->pw_name))) > word[1])
		word[1] = lgst;
	if ((lgst = (ft_strlen(tmp->gr_name))) > word[2])
		word[2] = lgst;
	if ((lgst = (ft_strlen(tmp->st_size))) > word[3])
		word[3] = lgst;
	if ((lgst = (ft_strlen(tmp->d_date[2]))) > word[4])
		word[4] = lgst;
	return (0);
}

void		what_display(char *s1, char *s2, t_flags *flag, int var)
{
	if (var == 1)
	{
		flag->m && flag->p ? ft_putdblstr(s2, ", ") : 0;
		flag->m && !flag->p ? ft_putdblstr(s1, ", ") : 0;
		!flag->m && flag->p ? ft_putdblstr(s2, ", ") : 0;
		!flag->m && !flag->p ? ft_putdblstr(s1, ", ") : 0;
	}
	else
	{
		flag->m && flag->p ? ft_putendl(s2) : 0;
		flag->m && !flag->p ? ft_putendl(s1) : 0;
		!flag->m && flag->p ? ft_putendl(s2) : 0;
		!flag->m && !flag->p ? ft_putendl(s1) : 0;
	}
}

void		print_spaces(int *word, char *s, int index)
{
	int		i;
	int		nb_spaces;

	i = -1;
	nb_spaces = word[index] - ft_strlen(s);
	while (++i < nb_spaces)
		ft_putchar(' ');
}

int			get_total(t_info *info, t_flags *flag)
{
	t_info	*tmp;
	int		total;

	tmp = info;
	total = 0;
	while (tmp)
	{
		if (flag->a == 1)
			total = total + tmp->st_blocks;
		else
		{
			if (tmp->d_name[0] != '.')
				total = total + tmp->st_blocks;
		}
		tmp = tmp->next;
	}
	return (total);
}

int			get_lgst_word(int *word, t_info *info, t_flags *flag)
{
	t_info	*tmp;
	int		lgst;

	tmp = info;
	lgst = 0;
	word[0] = (tmp && !flag->a && tmp->d_name[0] != '.' ?\
			ft_strlen(tmp->st_nlink) : 0);
	word[1] = (tmp && !flag->a && tmp->d_name[0] != '.' ?\
			ft_strlen(tmp->pw_name) : 0);
	word[2] = (tmp && !flag->a && tmp->d_name[0] != '.' ?\
			ft_strlen(tmp->gr_name) : 0);
	word[3] = (tmp && !flag->a && tmp->d_name[0] != '.' ?\
			ft_strlen(tmp->st_size) : 0);
	word[4] = (tmp && !flag->a && tmp->d_name[0] != '.' ?\
			ft_strlen(tmp->d_date[2]) : 0);
	while (tmp)
	{
		if (flag->a == 0 && tmp->d_name[0] != '.')
			f_wordtab(word, tmp);
		else if (flag->a == 1)
			f_wordtab(word, tmp);
		tmp = tmp->next;
	}
	return (0);
}
