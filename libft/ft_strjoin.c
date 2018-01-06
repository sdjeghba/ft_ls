/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:39:35 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:55:28 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp_s1;

	tmp_s1 = NULL;
	if (s1 && s2)
	{
		tmp_s1 = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
		if (!tmp_s1)
			return (NULL);
		ft_strcpy(tmp_s1, s1);
		ft_strcat(tmp_s1, s2);
	}
	return (tmp_s1);
}
