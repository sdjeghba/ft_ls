/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:35:32 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:47:43 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char			*cp_s1;
	char			*cp_s2;
	size_t			i;

	i = 0;
	cp_s1 = (char *)s1;
	cp_s2 = (char *)s2;
	while (i < n)
	{
		cp_s1[i] = cp_s2[i];
		i++;
	}
	return (s1);
}
