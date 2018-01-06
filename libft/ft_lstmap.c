/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:34:34 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:46:49 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alist;
	t_list	*new_list;
	t_list	*link;

	if (!lst || !f)
		return (0);
	link = f(lst);
	new_list = ft_lstnew(link->content, link->content_size);
	if (!new_list)
		return (0);
	alist = new_list;
	while (lst->next != NULL)
	{
		link = f(lst->next);
		new_list->next = ft_lstnew(link->content, link->content_size);
		if (new_list->next == NULL)
			return (0);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (alist);
}
