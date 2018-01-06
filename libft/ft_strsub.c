/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:41:34 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:58:46 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (start + len > ft_strlen(s))
		if (start <= ft_strlen(s))
			len = ft_strlen(s) - start;
	str = ft_strncpy(str, s + start, len);
	return (str);
}
