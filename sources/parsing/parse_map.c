/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:39:38 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/05 20:51:00 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_map_line_cpy(char *tmp_line, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->x * map-> y)
	{
		while (map->line[j] != '\n' && map->line[j] != '\0')
		{
			tmp_line[i] = map->line[j];
			i++;
			j++;
		}
		j++;
		while (tmp_line[i] != '\n' && tmp_line[i] != '\0')
			i++;
		i++;
	}
}

static int	ft_create_rect_map(t_map *map)
{
	char	*tmp_line;
	int		i;

	tmp_line = malloc(sizeof (char) * (map->x * map->y + 1)); // pe faire fonction update_line etc
	if (tmp_line == NULL)
	{
		print_error_fd("ft_parse_map: ", " _tmp_line malloc failed", 2);
		return (1);
	}
	ft_memset(tmp_line, ' ', map->x * map->y);
	tmp_line[map->x * map->y] = '\0';
	i = 1;
	while (i <= map->y)
	{
		tmp_line[map->x * i - 1] = '\n';
		i++;
	}
	ft_map_line_cpy(tmp_line, map);
	free (map->line);
	map->line = tmp_line;
	return (0);
}

int	ft_check_map(t_map *map, t_all *all)
{
	if (ft_create_rect_map(map) == 1)
		return (1);
	if (ft_scan_map(map, all) == 1)
		return (1);
	return (0);
}