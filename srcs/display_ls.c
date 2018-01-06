/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 21:26:26 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/06 15:27:23 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			display_smb_link(t_info *tmp)
{
	ssize_t	buf_size;
	char	buf[2048];

	buf_size = readlink(tmp->path, buf, 2047);
	if (buf_size > 0)
	{
		buf[buf_size] = '\0';
		ft_putdblstr(" -> ", buf);
	}
	return (0);
}

void		display_date(char **date, int *word, int val, t_flags *flag)
{
	date[4][4] = '\0';
	if (flag->big_t)
	{
		ft_putdblstr(date[1], "  ");
		print_spaces(word, date[2], 4);
		ft_putdblstr(date[2], " ");
		print_spaces(word, date[3], 4);
		ft_putdblstr(date[3], " ");
		print_spaces(word, date[4], 4);
		ft_putdblstr(date[4], " ");
	}
	else
	{
		date[3][5] = '\0';
		ft_putdblstr(date[1], "  ");
		print_spaces(word, date[2], 4);
		ft_putdblstr(date[2], " ");
		val == 1 ? ft_putchar(' ') : 0;
		val == 1 ? ft_putdblstr(date[4], " ") : ft_putdblstr(date[3], " ");
	}
}

void		display_details(t_info *tmp, int *word, t_flags *flag)
{
	int		val;

	val = 0;
	if (tmp->mtime > time(NULL) || tmp->mtime < (time(NULL) - 15778800))
		val = 1;
	ft_putstr(tmp->rights);
	check_acl(tmp->path);
	print_spaces(word, tmp->st_nlink, 0);
	ft_putdblstr(tmp->st_nlink, " ");
	ft_putdblstr(tmp->pw_name, "  ");
	!flag->o ? print_spaces(word, tmp->pw_name, 1) : 0;
	!flag->o ? ft_putdblstr(tmp->gr_name, "  ") : 0;
	print_spaces(word, tmp->gr_name, 2);
	print_spaces(word, tmp->st_size, 3);
	ft_putdblstr(tmp->st_size, " ");
	display_date(tmp->d_date, word, val, flag);
	flag->big_g ? put_color(tmp->rights[0]) : 0;
	ft_putstr(tmp->d_name);
	tmp->rights[0] == 'd' && flag->p ? ft_putchar('/') : 0;
	ft_putstr(CANCEL);
	tmp->rights[0] == 'l' ? display_smb_link(tmp) : 0;
	ft_putchar('\n');
}

void		display_files(t_info *info, t_flags *flag)
{
	t_info	*tmp;
	char	*s;
	int		var;

	tmp = info;
	s = NULL;
	var = (flag->m ? 1 : 0);
	while (tmp)
	{
		ft_putstr(CANCEL);
		flag->big_g ? put_color(tmp->rights[0]) : 0;
		s = (tmp->rights[0] == 'd' && flag->p ? ft_strjoin(tmp->d_name, "/") :
				tmp->d_name);
		if (flag->a == 0)
		{
			if (tmp->d_name[0] != '.')
				tmp->next ? what_display(tmp->d_name, s, flag, var) :
					what_display(tmp->d_name, s, flag, 0);
		}
		else
			tmp->next ? what_display(tmp->d_name, s, flag, var) :
				what_display(tmp->d_name, s, flag, 0);
		s && flag->p && tmp->rights[0] == 'd' ? ft_strdel(&s) : 0;
		tmp = tmp->next;
	}
}

void		display_list(t_info *info, t_flags *flag)
{
	t_info	*tmp;
	int		word[5];
	int		total;
	int		v;

	tmp = info;
	v = (flag->one != 0 || flag->m ? 1 : 0);
	v == 1 ? display_files(info, flag) : 0;
	if (v == 1)
		return ;
	total = get_total(info, flag);
	lstlen(tmp) > 2 ? ft_putstr("total ") : 0;
	lstlen(tmp) > 2 ? ft_putnbr(total) : 0;
	lstlen(tmp) > 2 ? ft_putchar('\n') : 0;
	get_lgst_word(word, info, flag);
	while (tmp)
	{
		if (flag->a == 0)
		{
			tmp->d_name[0] != '.' ? display_details(tmp, word, flag) : 0;
		}
		else
			display_details(tmp, word, flag);
		tmp = tmp->next;
	}
}
