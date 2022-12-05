/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:30:27 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/05 15:23:40 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_player(char *map_line, char *player, int *flag)
{
	int	i;

	i = 0;
	*flag = 0;
	while (map_line[i])
	{
		if ((map_line[i] == 'N' || map_line[i] == 'S' || map_line[i] == 'E'
			|| map_line[i] == 'W'))
		{
			*player = map_line[i];
			(*flag)++;
		}
		i++;
	}
	if (*flag != 1)
	{
		if (*flag == 0)
			print_error_fd("ft_check_player", "player is missing", 2);
		else
			print_error_fd("ft_check_player", "multiplayers fobbiden", 2);
		return (1);
	}
	return (0);
}

static int	ft_check_chars(char *map_line)
{
	const char	map_chars[] = MAP_CHARS;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map_line[i])
	{
		j = 0;
		while (map_chars[j] && map_chars[j] != map_line[i])
			j++;
		if(map_chars[j] != map_line[i])
		{
			print_error_fd("ft_check_chars", "map: forbidden character", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_scan_map(t_map *map, t_all *all)
{
	if (ft_check_chars(map->line) == 1)
		return (1);
	else if (ft_check_player(map->line, &all->pos.p, &all->flag) == 1)
		return (1);
	// else if (ft_check_player(map->line) == 1)
	// 	return (1);
	// else if (ft_check_walls(map->line) == 1)
	// 	return (1);
	// else if ( ft_check_empty_char(map->line) == 1)
	// 	return (1);
	return (0);
}
