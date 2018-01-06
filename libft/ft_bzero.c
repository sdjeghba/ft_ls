/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:33:07 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:21:58 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = 0;
}