/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:02 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/30 15:41:24 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_parse_map(t_map *map)
// {
// 	char	**tab_tmp;
// 	int		len;

	
	
// 	return (0);
// }

static int	ft_create_map(char *line, t_map *map)
{
	char	*tmp;

	if (map->line == NULL)
	{
		map->line = ft_strdup(line);
		if (map->line == NULL)
		{
			print_error_fd("ft_get_map: ", "strdup failed", 2);
			return (1);
		}
	}
	else
	{
		tmp = map->line;
		map->line = ft_strjoin_no_free(tmp, line);
		free(tmp);
		if (map->line == NULL)
		{
			print_error_fd("ft_get_map: ", "strjoin failed", 2);
			return (1);
		}
	}
	// return (ft_parse_map(map));
	return (0);
}

static int	ft_map_x_max(char *line, int *x)
{
	int	tmp;

	tmp = ft_strlen(line);
	if (tmp > *x)
		*x = tmp;//a verifier si marche comme je veux
	return (0);
}

int	ft_get_map(char *line, t_map *map, t_all *all)
{
	int	i;

	i = 0;
	ft_skip(&line[i], &i);
	if (line[i] == '\0' && map->y == 0)
		return (0);
	else if (line[i] == '\0' && map->y != 0 && all->flag == 6)
	{
		all->flag++;
		return (0);
	}
	else if (line[i] != '\0' && map->y != 0 && all->flag > 6)
	{
		print_error_fd("ft_get_map: ", "invalid map: empty line", 2);
		return (1);
	}
	map->y++;
	ft_map_x_max(line, &map->x);
	return (ft_create_map(line, map));
}
