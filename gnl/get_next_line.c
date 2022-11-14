/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:23:57 by agouet            #+#    #+#             */
/*   Updated: 2022/11/14 14:12:07 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_chr(const char *s, int c)
{
	if (!s)
		return (1);
	while (*s)
	{
		if ((char) *s == (char) c)
			return (0);
		s++;
	}
	return (1);
}

void	ft_freee( char *line, char *save_buf)
{
	free(save_buf);
	free(line);
}

char	*get_next_line(int fd)
{
	char		*save_buf;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*next;
	char		*save_line;

	save_line = NULL;
	if (fd < 0 || (read (fd, buf, 0) < 0) || BUFFER_SIZE < 0)
	{
		free(next);
		return (NULL);
	}
	while (ft_chr(save_line, '\n'))
	{
		buf[read (fd, buf, BUFFER_SIZE)] = '\0';
		if (!buf[0] && !next)
			return (save_line);
		save_buf = ft_strjoin(next, buf);
		next = ft_mstrchr(save_buf, '\n');
		line = ft_substr(save_buf, 0, (ft_strlen(save_buf) - ft_strlen(next)));
		save_line = ft_strjoin(save_line, line);
		ft_freee(line, save_buf);
	}
	return (save_line);
}