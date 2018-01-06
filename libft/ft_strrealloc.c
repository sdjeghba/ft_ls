/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:38:46 by sdjeghba          #+#    #+#             */
/*   Updated: 2017/12/26 14:38:48 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrealloc(char *str, int size)
{
	char *s;

	if (!str)
	{
		s = ft_strnew(size);
		return (s);
	}
	s = ft_strnew(ft_strlen(str) + size);
	ft_strcpy(s, str);
	ft_strdel(&str);
	return (s);
}
