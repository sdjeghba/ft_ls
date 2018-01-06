/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:40:29 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:56:25 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	if (!n)
		return (0);
	i = 0;
	while (i < n - 1 && s1[i] == s2[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
