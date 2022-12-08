/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_tex_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/08 15:46:17 by esmirnov         ###   ########.fr       */
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
		return (msg_err("ft_get_img_path: invalide path", *path, 2));
	ft_skip(&line[i], &i);
	if (line == NULL || line[i] == '\0')
		return (msg_err("ft_get_img_path: invalide path", *path, 2));
	*path = ft_strdup_path(&line[i]);
	if (path == NULL)
		return (msg_err("ft_get_img_path: strdup failed", NULL, 2));
	if (ft_open_file(*path, &fd, ".xpm") == 1)
		return (1);
	(*flag)++;
	return (0);
}

int	ft_get_tex_img( char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O' && all->tex[NORTH].dir == NULL)
		ret = ft_get_img_path(&line[i + 2], &all->tex[NORTH].dir, &all->flag);
	else if (line[i] == 'S' && line[i + 1] == 'O' && all->tex[SOUTH].dir == NULL)
		ret = ft_get_img_path(&line[i + 2], &all->tex[SOUTH].dir, &all->flag);
	else if (line[i] == 'W' && line[i + 1] == 'E' && all->tex[WEST].dir == NULL)
		ret = ft_get_img_path(&line[i + 2], &all->tex[WEST].dir, &all->flag);
	else if (line[i] == 'E' && line[i + 1] == 'A' && all->tex[EAST].dir == NULL)
		ret = ft_get_img_path(&line[i + 2], &all->tex[EAST].dir, &all->flag);
	else
		return (msg_err("ft_get_tex_img: invalid file", NULL, 2));
	return (ret);
}
