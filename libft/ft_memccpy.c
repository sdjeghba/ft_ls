/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:34:58 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:47:16 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*dst;
	const char		*srcs;

	dst = (char *)dest;
	srcs = (const char *)src;
	while (n--)
	{
		*dst = *srcs;
		if (*srcs == (char)c)
		{
			dst++;
			return (dst);
		}
		dst++;
		srcs++;
	}
	return (0);
}
