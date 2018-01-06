/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:39:44 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:55:36 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t					ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				len_dst;
	size_t				len_src;
	int					i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	i = 0;
	if (size < (len_dst + 1))
		return (size + len_src);
	while (i < (int)(size - len_dst - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
