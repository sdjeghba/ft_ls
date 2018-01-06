/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:34:27 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:46:11 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f) (t_list *elem))
{
	if (lst && f)
	{
		if (lst->next == NULL)
			f(lst);
		else
		{
			f(lst);
			ft_lstiter(lst->next, f);
		}
	}
}
