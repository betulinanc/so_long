/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:10:14 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_str(int fd, char *st)
{
	int		rd_byte;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	rd_byte = 1;
	while (!ft_strchr(st, '\n') && rd_byte != 0)
	{
		rd_byte = read(fd, buff, BUFFER_SIZE);
		if (rd_byte == -1)
		{
			free(st);
			free(buff);
			return (0);
		}
		buff[rd_byte] = '\0';
		st = ft_strjoin(st, buff);
	}
	free(buff);
	return (st);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*st;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	st = ft_get_str(fd, st);
	if (!st)
		return (0);
	line = ft_get_line(st);
	st = ft_get_new_str(st);
	return (line);
}
