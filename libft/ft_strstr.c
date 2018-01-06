/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:41:26 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:58:32 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char					*ft_strstr(const char *s1, const char *s2)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i + j] == s2[j])
		{
			while (s1[i + j] == s2[j] && s2[j])
				j++;
			if (!s2[j])
				return ((char *)&s1[i]);
			i += 1;
		}
		i++;
	}
	return (0);
}
