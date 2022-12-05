/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:02 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/02 17:08:08 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_fill_map_line(char *line, t_map *map)
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
	else if (line[i] == '\0' && map->y != 0 && all->flag > 6)
		return (0);
	ft_map_x_max(line, &map->x);
	map->y++;
	return (ft_fill_map_line(line, map));
}
