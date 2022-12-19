/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_scan_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:30:27 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/16 13:44:41 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_scan_zero(char *map_line, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y * map->x)
	{
		if (map_line[i] == '0')
		{
			if (i / map->x == 0 || i / map->x == map->y)
				return (msg_err("ft_scan_zero", "invalid map\n", 2));
			else if (map_line[i - 1] == ' ' || map_line[i + 1] == ' '
				|| map_line[i - map->x] == ' ' || map-> line[i + map->x] == ' '
				|| map_line[i - 1] == '\n' || map_line[i + 1] == '\n'
				|| map_line[i - map->x] == '\n'
				|| map-> line[i + map->x] == '\n')
				return (msg_err("ft_scan_zero", "invalid map\n", 2));
		}
		i++;
	}
	return (0);
}

static int	ft_scan_player(char *map_line, char *player, int *flag, t_all *all)
{
	int	i;

	i = 0;
	*flag = 0;
	read_pos_ini(all);
	while (map_line[i] != '\0')
	{
		if ((map_line[i] == 'N' || map_line[i] == 'S' || map_line[i] == 'E'
				|| map_line[i] == 'W'))
		{
			*player = map_line[i];
			map_line[i] = '0';
			(*flag)++;
		}
		i++;
	}
	if (*flag != 1)
	{
		if (*flag == 0)
			return (msg_err("ft_scan_player", "player is missing\n", 2));
		else
			return (msg_err("ft_scan_player", "multiplayers fobbiden\n", 2));
	}
	return (0);
}

static int	ft_scan_forbid_chars(char *map_line)
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
		if (map_chars[j] != map_line[i])
			return (msg_err("ft_scan_forbid_chars", "forbidden character\n", 2));
		i++;
	}
	return (0);
}

int	ft_scan_map(t_map *map, t_all *all)
{
	if (ft_scan_forbid_chars(map->line) == 1)
		return (1);
	else if (ft_scan_player(map->line, &all->pos.p, &all->flag, all) == 1)
		return (1);
	else if (ft_scan_zero(map->line, map) == 1)
		return (1);
	return (0);
}
