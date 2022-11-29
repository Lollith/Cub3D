/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:02 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/29 12:00:19 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_map(t_map *map)
{
	char	**tab_tmp;
	int		len;

	
	
	return (0);
}

static int	ft_create_map(char *line, t_map *map, t_all *all)
{
		if (map->line == NULL)
	{
		print_error_fd("ft_get_map: ", "strdup failed", 2);
		map->line = ft_strdup(line);
		return (1);
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
	// len = ft_strlen(line);
	// if (map->x < len)
	// 	map->x = len;
	// map->y++;
	return (ft_parse_map(map));
}

int	ft_get_map(char *line, t_map *map, t_all *all)//voir pour envoyer que le flag
{
	char	*tmp;
	int		i;

	i = 0;
	ft_skip(&line[i], &i);
	if (map->y == 0 && line[i] == '\0')
		return (0);
	else if (map->y != 0 && line[i] != '\0' && all->flag > 6)//changement de flag si apres y != 0 rencontre ligne vide?
	{
		print_error_fd("ft_get_map: ", "invalid map: empty line", 2);
		return (1);
	}
	return (ft_create_map(line, map, all));
}
// *ft_strjoin_no_free(char const *s1, char const *s2)