/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:41:20 by sdjeghba          #+#    #+#             */
/*   Updated: 2017/09/13 17:17:25 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_word_nb(char const *s, char c)
{
	size_t	word_nb;

	word_nb = ((*s == c) ? (0) : (1));
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			word_nb++;
		s++;
	}
	return (word_nb);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s != c && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

static void		ft_freetab(char **tab, int i)
{
	while (i >= 0)
		free(tab[i--]);
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(tab = malloc(ft_word_nb(s, c) * sizeof(char *) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(tab[i] = ft_strsub(s, 0, ft_word_len(s, c))))
			{
				ft_freetab(tab, i);
				return (NULL);
			}
			s += ft_word_len(s, c);
			i++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
