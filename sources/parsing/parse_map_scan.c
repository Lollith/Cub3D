/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:30:27 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/05 11:54:17 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_player(char *map_line, char *player, int *flag)
{
	int	i;

	i = 0;
	*flag = 0;
	printf("BEGIN Player orien is %c\nflag is %d\n i is %d\n", *player, *flag, i);
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
	printf("Player orien is %c\nflag is %d\n i is %d\n", *player, *flag, i);
	if (*flag != 1)
	{
		if (*flag == 0)
			print_error_fd("invalid file", "player is missing", 2);
		else
			print_error_fd("invalid file", "invalid player position(s)", 2);
		return (1);
	}
	return (0);
}

// ft_check_chars(map->line)

int	ft_scan_map(t_map *map, t_all *all)
{
	if (ft_check_player(map->line, &all->pos.p, &all->flag) == 1)
		return (1);
	// if (ft_check_chars(map->line) == 1)
	// 	return (1);
	// else if (ft_check_player(map->line) == 1)
	// 	return (1);
	// else if (ft_check_walls(map->line) == 1)
	// 	return (1);
	// else if ( ft_check_empty_char(map->line) == 1)
	// 	return (1);
	return (0);
}
