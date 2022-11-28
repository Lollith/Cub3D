/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:02 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/28 17:51:26 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_map(t_map *map)
{
	char	**tab_tmp;
	int		len;

	
	
	return (0);
}

int		ft_get_map(char *line, t_map *map)
{
	// int		len;
	char	*tmp;

	if (map->line == NULL)
		map->line = ft_strdup(line);
	else
	{
		tmp = map->line;
		map->line = ft_strjoin_no_free(tmp, line);
		free(tmp);
	}
	if (map->line == NULL)
	{
		print_error_fd("ft_get_map: strdup or strjoin failed", NULL, 2);
		return (1);
	}
	// len = ft_strlen(line);
	// if (map->x < len)
	// 	map->x = len;
	// map->y++;
	return (ft_parse_map(map));
}
// *ft_strjoin_no_free(char const *s1, char const *s2)