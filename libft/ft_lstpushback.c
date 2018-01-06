/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:15:56 by salemdje          #+#    #+#             */
/*   Updated: 2017/09/13 13:42:25 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstpushback(void const *content, size_t content_size,\
		t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	if (tmp == NULL)
		*list = ft_lstnew(content, content_size);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
}
