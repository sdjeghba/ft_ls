/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:32:28 by sdjeghba          #+#    #+#             */
/*   Updated: 2017/12/30 06:08:48 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

static int		fill_line(char **line, char *buf)
{
	char	*tmp;

	if ((tmp = ft_strchr(buf, '\n')))
	{
		*line = ft_strrealloc(*line, tmp - buf);
		ft_strncat(*line, buf, tmp - buf);
		ft_strncpy(buf, tmp + 1, ft_strlen(tmp));
		return (1);
	}
	if (ft_strlen(buf))
	{
		*line = ft_strrealloc(*line, ft_strlen(buf));
		ft_strncat(*line, buf, ft_strlen(buf));
		*buf = '\0';
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*buf[MAX_FD];
	int			ret;

	if (fd < 0 || fd >= MAX_FD || !line || BUFF_SIZE < 1
		|| (!buf[fd] && !(buf[fd] = ft_strnew(BUFF_SIZE))) ||
		read(fd, "", 0) < 0)
		return (-1);
	*line = NULL;
	if (fill_line(line, buf[fd]))
		return (1);
	while ((ret = read(fd, buf[fd], BUFF_SIZE)) > 0)
	{
		buf[fd][ret] = '\0';
		if (fill_line(line, buf[fd]))
			return (1);
	}
	if (*line)
		return (1);
	ft_strdel(&buf[fd]);
	return (0);
}
