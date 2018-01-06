/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 21:49:51 by salemdje          #+#    #+#             */
/*   Updated: 2017/05/05 16:11:29 by salemdje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_display_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		ft_putendl((char *)tmp->content);
		tmp = tmp->next;
	}
}
