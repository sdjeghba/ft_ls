/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:22:39 by salemdje          #+#    #+#             */
/*   Updated: 2017/09/05 18:38:55 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_lstlen(t_list **list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
