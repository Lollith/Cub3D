/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:49:00 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/18 14:28:26 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_size(char **av, t_map *map) // only for the beginning msquare map
{
	int		fd;
	char	*line;

	map->y = 0;
	map->x = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
		print_error_fd("map_size: invalid fd\n", NULL, 2);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (map->x < (int)ft_strlen(line) - 1)
			map->x = ft_strlen(line) - 1;
		free (line);
		map->y++;
	}
	close (fd);
}

int	init_square_map(char **av, t_map *map)
{
	map_size(av, map);
	map_read(av, map);
	return (0);
}

void	map_read(char **av, t_map *map)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
	{
		print_error_fd("map_read: invalid fd\n", NULL, 2);
		return ;
	}
	i = 0;
	map->line = get_next_line(fd);
	while (i - 1 <= map->y)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tmp = ft_strjoin_no_free(map->line, line);
		free (map->line);
		free (line);
		map->line = tmp;
		i++;
	}
	close (fd);
	// ft_map_read_check(data);
}
