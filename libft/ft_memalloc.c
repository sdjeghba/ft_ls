/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:34:51 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:47:07 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memalloc(size_t size)
{
	void			*s;

	if (!(s = (void *)malloc(size)))
		return (NULL);
	s = ft_memset(s, '\0', size);
	return (s);
}
