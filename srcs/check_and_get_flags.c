/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:56:13 by salemdje          #+#    #+#             */
/*   Updated: 2018/01/06 15:26:14 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		fill_flags(char c, t_flags *flag)
{
	flag->l = ((c == 'l') ? 1 : flag->l);
	flag->r = ((c == 'r') ? 1 : flag->r);
	flag->a = ((c == 'a') ? 1 : flag->a);
	flag->t = ((c == 't') ? 1 : flag->t);
	flag->o = ((c == 'o') ? 1 : flag->t);
	flag->big_g = ((c == 'G') ? 1 : flag->big_g);
	flag->p = ((c == 'p') ? 1 : flag->p);
	flag->big_t = ((c == 'T') ? 1 : flag->big_t);
	flag->m = ((c == 'm') ? 1 : flag->m);
	flag->one = ((c == '1') ? 1 : flag->one);
	flag->upp_r = ((c == 'R') ? 1 : flag->upp_r);
}

int			check_first_char(char *av)
{
	char	*tmp;

	tmp = av;
	if (*tmp && *tmp != '-')
		return (NOT_F);
	tmp++;
	if (!*tmp || *tmp == '-')
		return (NOT_F);
	return (0);
}

int			check_good_char(char *tmp, t_flags *flag)
{
	flag->invalid_o = *tmp;
	if (*tmp == 'r' || *tmp == 'a' || *tmp == 'R' || *tmp == 'l' ||
			*tmp == 't' || *tmp == 'G' || *tmp == 'p' || *tmp == 'T' ||
			*tmp == '1' || *tmp == 'm' || *tmp == 'o')
		fill_flags(*tmp, flag);
	else
		illegal_option(*tmp);
	return (0);
}

int			check_flags(char **av, int ac, int *arg, t_flags *flag)
{
	char	*tmp;

	tmp = NULL;
	while ((*arg)++ < ac)
	{
		tmp = av[*arg];
		if (!(av[*arg]))
			return (-1);
		if (check_first_char(av[*arg]) == NOT_F)
			return (NOT_F);
		else
		{
			tmp++;
			if (*tmp)
				while (*tmp)
				{
					check_good_char(tmp, flag);
					tmp++;
				}
			else
				return (NOT_F);
		}
	}
	return (0);
}
