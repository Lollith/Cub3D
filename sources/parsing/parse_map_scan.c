/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:30:27 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/06 17:28:58 by esmirnov         ###   ########.fr       */
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
			{
				print_error_fd("ft_scan_zero", "invalid map", 2);
				return (1);
			}
			else if (map_line[i - 1] == ' ' || map_line[i + 1] == ' '
				|| map_line[i - map->x] == ' ' || map-> line[i + map->x] == ' '
				|| map_line[i - 1] == '\n' || map_line[i + 1] == '\n'
				|| map_line[i - map->x] == '\n'
				|| map-> line[i + map->x] == '\n')
			{
				print_error_fd("ft_scan_zero", "invalid map", 2);
				return (1);
			}
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
			print_error_fd("ft_scan_player", "player is missing", 2);
		else
			print_error_fd("ft_scan_player", "multiplayers fobbiden", 2);
		return (1);
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
		{
			print_error_fd("ft_scan_chars", "map: forbidden character", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_scan_map(t_map *map, t_all *all)
{
	if (ft_scan_player(map->line, &all->pos.p, &all->flag, all) == 1)
		return (1);
	else if (ft_scan_forbid_chars(map->line) == 1)
		return (1);
	else if (ft_scan_zero(map->line, map) == 1)
		return (1);
	return (0);
}

// static int	ft_scan_chars(char *map_line, t_map *map)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	ret = 0;
// 	while (i < map->y * map->x)
// 	{
// 		if (map_line[i] == ' ')
// 			i++;
// 		else if (map_line[i] == '1')
// 			i++;
// 		else if (map_line[i] == '0')
// 			ret = ft_zero(&i, map);
// 		else if (map_line[i] == '\n')
// 			i++;
// 		else
// 		{
// 			print_error_fd("ft_scan_chars", "map: forbidden character", 2);
// 			return (1);
// 		}
// 	}
// 	return (ret);
// }

// static int	ft_check_walls(char *map_line, int x, int y)
// {
// 	int	i;

// 	i = 0;
// 	while (map_line[i])
// 	{
// 		ft_skip(&map_line[i], &i);
// 		if (map_line[i] == '0')
// 		{
// 		}
// 	}
// }
/*                                                                            */
/* ************************************************************************** */

// static int	ft_scan_empty_char(char *map_line, t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->y * map->x)
// 	{
// 		if (map_line[i] == '0')
// 		{
// 			if (i / map->x == 0 || i / map->x == map->y)
// 			{
// 				print_error_fd("ft_scan_empty_char", "invalid map", 2);
// 				return (1);
// 			}
// 			else if (map_line[i - 1] == ' ' || map_line[i + 1] == ' '
// 				|| map_line[i - map->x] == ' ' || map-> line[i + map->x] == ' ')
// 				)
// 			{
				
// 			}
// 		}
// 	}
// 	return (0);
// }

// static int	ft_scan_spaces(char *map_line, t_map *map)
// {
// 	int	i;
// 	int ret;

// 	i = 0;
// 	ret = 0;
// 	while (i < map->y * map->x)
// 	{
// 		if (map_line[i] == ' ')
// 			ret = ft_space(map_line, &i);
// 		else if (map_line[i] == ' ')
// 		{
// 			if ((map_line[i - 1] != ' ' && map_line[i - 1] != '1'
// 					&& map_line[i - 1] != '\n') || (map_line[i + 1] != ' '
// 					&& map_line[i + 1] != '1' && map_line[i + 1] != '\n')
// 				|| (map_line[i - map->x] != ' ' && map_line[i - map->x] != '1'
// 					&& map_line[i - map->x] != '\n')
// 				|| (map_line[i - map->x] != ' ' && map_line[i - map->x] != '1'
// 					&& map_line[i - map->x] != '\n'))
// 			{
// 				print_error_fd("ft_scan_spaces", "invalid map", 2);
// 				return (1);
// 			}
// 		}
// 	}
// 	return (0);
// }
/* ************************************************************************** */