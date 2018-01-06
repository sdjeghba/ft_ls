/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:41:09 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:58:00 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while (i >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
