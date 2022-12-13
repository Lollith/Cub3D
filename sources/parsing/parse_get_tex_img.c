/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_tex_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/13 14:04:44 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_img_path(char *line, char **path, int *flag)
{
	int	i;
	int	fd;

	i = 0;
	fd = -1;
	if (line[i] != ' ')
		return (msg_err("ft_get_img_path: invalid path: miss space", *path, 2));
	ft_skip(&line[i], &i);
	if (line == NULL || line[i] == '\0')
		return (msg_err("ft_get_img_path: invalid path: empty path", *path, 2));
	*path = ft_strdup_path(&line[i]);
	if (*path == NULL || ft_open_file(*path, &fd, ".xpm") == 1)
		return (1);
	(*flag)++;
	return (0);
}

int	ft_get_tex_img( char *line, t_all *all)
{
	int	i;
	int	j;
	int	h;
	int	r;

	i = 0;
	h = i + 1;
	j = i + 2;
	if (line[i] == 'N' && line[h] == 'O' && all->tex[NORTH].dir == NULL)
		r = ft_get_img_path(&line[j], &all->tex[NORTH].dir, &all->flag);
	else if (line[i] == 'S' && line[h] == 'O' && all->tex[SOUTH].dir == NULL)
		r = ft_get_img_path(&line[j], &all->tex[SOUTH].dir, &all->flag);
	else if (line[i] == 'W' && line[h] == 'E' && all->tex[WEST].dir == NULL)
		r = ft_get_img_path(&line[j], &all->tex[WEST].dir, &all->flag);
	else if (line[i] == 'E' && line[h] == 'A' && all->tex[EAST].dir == NULL)
		r = ft_get_img_path(&line[j], &all->tex[EAST].dir, &all->flag);
	else
		return (msg_err("ft_get_tex_img: invalid file", NULL, 2));
	return (r);
}
