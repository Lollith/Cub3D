/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/02 16:33:46 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse_map(t_map *map)
{
	if (ft_create_rect_map(map) == 1)
		return (1);
	return (0);
}

static int	ft_get_tex_map(char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (all->flag < 6)
	{
		ft_skip(&line[i], &i);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			ret = ft_get_tex_img(&all->tex, &line[i], all);
		else if (line[i] == 'F' || line[i] == 'C')
			ret = ft_get_tex_color(&all->tex, &line[i], all);
		else if (line[i] == '\0')
			return (0);
		else
		{
			print_error_fd("ft_get_tex_map: invalide file", NULL, 2);
			return (1);
		}
	}
	else
		ret = ft_get_map(line, &all->map, all);
	return (ret);
}

int	ft_get_info(char *av, t_all *all)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
	{
		print_error_fd("ft_get_info: invalid fd", NULL, 2);
		return (1);
	}
	line = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL) // a confirmer avec Adeline EOF => NULL et erreur NULL pe check structure vide ou pas et en fonction reagit EOF ou pb de lecture
			break ;
		if (ft_get_tex_map(line, all) == 1)
		{
			free (line);
			close (fd);
			return (1);
		}
		free (line);
	}
	close (fd);
	return (0);
}

int	ft_parse(char *av, t_all *all)
{
	if (ft_get_info(av, all) == 1)
		return (1);
	if (ft_parse_map(&all->map) == 1)
		return (1);
	return (0);
}

// int	ft_parse_map(t_map *map)
// {
// 	// char	*tmp_line;
// 	// char	*tmp;
// 	// int		i;
// 	// int		j;

// 	if (ft_create_rect_map(map) == 1)
// 		return (1);
// 	// tmp_line = malloc(sizeof (char) * (map->x * map->y + 1)); // pe faire fonction update_line etc
// 	// if (tmp_line == NULL)
// 	// {
// 	// 	print_error_fd("ft_parse_map: ", " _tmp_line malloc failed", 2);
// 	// 	return (1);
// 	// }
// 	// ft_memset(tmp_line, ' ', map->x * map->y);
// 	// tmp_line[map->x * map->y] = '\0';
// 	// i = 1;//put \n at the end
// 	// while (i <= map->y)
// 	// {
// 	// 	tmp_line[map->x * i] = '\n';
// 	// 	i++;
// 	// }
// 	// i = 0;// put map line in tmp line
// 	// j = 0;
// 	// while (i < map->x * map-> y)
// 	// {
// 	// 	while (map->line[j] != '\n' && map->line[j] != '\0')
// 	// 	{
// 	// 		tmp_line[i] = map->line[j];
// 	// 		i++;
// 	// 		j++;
// 	// 	}
// 	// 	j++;
// 	// 	while (tmp_line[i] != '\n' && tmp_line[i] != '\0')
// 	// 		i++;
// 	// 	i++;
// 	// }
// 	// tmp = map->line;
// 	// map->line = tmp_line;
// 	// free (tmp);
// 	return (0);
// }