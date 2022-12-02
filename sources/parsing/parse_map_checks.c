/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:30:27 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/02 17:44:34 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

ft_check_chars(map->line)

int	ft_check_map(t_map *map)
{
	if (ft_check_chars(map->line) == 1)
		return (1);
	else if (ft_check_player(map->line) == 1)
		return (1);
	else if (ft_check_walls(map->line) == 1)
		return (1);
	else if ( ft_check_empty_char(map->line) == 1)
		return (1);
}