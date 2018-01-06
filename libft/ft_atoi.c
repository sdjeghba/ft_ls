/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:32:55 by sdjeghba          #+#    #+#             */
/*   Updated: 2016/12/24 21:21:34 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		negatif;

	i = 0;
	nbr = 0;
	negatif = 0;
	while ((str[i] == ' ') || (str[i] >= 7 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		negatif = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	if (negatif == 1)
		return (-nbr);
	else
		return (nbr);
}
