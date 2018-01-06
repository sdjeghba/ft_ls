/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:35:09 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:47:25 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*cp_s;

	i = 0;
	cp_s = (unsigned char *)s;
	while (i < n)
	{
		if (*cp_s == (unsigned char)c)
			return ((void *)cp_s);
		i++;
		cp_s++;
	}
	return (NULL);
}
