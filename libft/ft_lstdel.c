/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:34:11 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:45:53 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void*, size_t))
{
	if (alst && *alst && del)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		else
		{
			ft_lstdel(&(*alst)->next, del);
			ft_lstdelone(alst, del);
		}
	}
}
