/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_between_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 15:42:28 by salemdje          #+#    #+#             */
/*   Updated: 2017/09/13 13:34:52 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_place_between_str(char *s1, char *s2, char *c)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (s1 && s2)
	{
		tmp = ft_strjoin(s1, c);
		tmp2 = ft_strjoin(tmp, s2);
		ft_memdel((void**)&tmp);
	}
	return (tmp2);
}
