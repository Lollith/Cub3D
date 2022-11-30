/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:24:02 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/30 14:54:59 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_parse_map(t_map *map)
// {
// 	char	**tab_tmp;
// 	int		len;

	
	
// 	return (0);
// }

// static int	ft_create_map(char *line, t_map *map, t_all *all)
// {
// 	char	*tmp;

// 	if (map->line == NULL)
// 	{
// 		print_error_fd("ft_get_map: ", "strdup failed", 2);
// 		map->line = ft_strdup(line);
// 		return (1);
// 	}
// 	else
// 	{
// 		tmp = map->line;
// 		map->line = ft_strjoin_no_free(tmp, line);
// 		free(tmp);
// 		if (map->line == NULL)
// 		{
// 			print_error_fd("ft_get_map: ", "strjoin failed", 2);
// 			return (1);
// 		}
// 	}
// 	// len = ft_strlen(line);
// 	// if (map->x < len)
// 	// 	map->x = len;
// 	// map->y++;
// 	return (ft_parse_map(map));
// }

static int	ft_map_x_max(char *line, int *x)
{
	int	tmp;

	tmp = ft_strlen(line);
	if (tmp > *x)
		*x = tmp;//a verifier si marche comme je veux
	return (0);
}

/*
** At first I skip all empty lines before map(map_y == 0 line[end] == '\0')
** If line is not empty I increase the all->y count by 1 and
** look for the length of the line compared to the previous one.
** The max len will be saved in all->x(ft_map_x_max).
** If the empty line found after non empty line 
** the all->flag is increased by 1 (all->flag > 6). 
** all->flag == 7 means end of map. If I will found any other non empty line after that
** will means an error in map.
*/
int	ft_get_map(char *line, t_map *map, t_all *all)//voir pour envoyer que le flag
{
	int	i;

	i = 0;
	ft_skip(&line[i], &i);
	if (line[i] == '\0' && map->y == 0)
		return (0);
	if (line[i] == '\0' && all->flag == 6)//changement de flag si apres y != 0 rencontre ligne vide?
	{	
		all->flag++;
		return (0);
	}
	if (line[i] == '\0' && all->flag > 6)
	{
		print_error_fd("ft_get_map: ", "invalid map: empty line", 2);
		return (1);
	}
	map->y++;
	ft_map_x_max(line, &map->x);
	printf("y is %d, x is %d, flag is %d\n", map->y, map->x, all->flag);
	// return (ft_create_map(line, map, all));
	return (0);
}
// *ft_strjoin_no_free(char const *s1, char const *s2)


