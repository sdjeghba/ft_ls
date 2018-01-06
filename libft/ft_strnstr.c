/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:41:02 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:57:14 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char					*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	size_t				j;

	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		if (s1[i + j] == s2[j])
		{
			while (s1[i + j] == s2[j] && s2[j] && (i + j) < n)
				j++;
			if (!s2[j])
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
