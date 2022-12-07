/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/07 13:09:51 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_img_path(char *line, char **path, int *flag)
{
	int	i;

	i = 0;
	if (line[i] != ' ')
	{
		print_error_fd("ft_get_img_path: invalide tex. description", NULL, 2);
		return (1);
	}
	ft_skip(&line[i], &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_get_img_path: invalide tex. description", NULL, 2);
		return (1);
	}
	*path = ft_strdup_path(&line[i]);
	if (path == NULL)
	{
		print_error_fd("ft_get_img_path: strdup failed", NULL, 2);
		return (1);
	}
	if (check_file_path(*path) == 1)//to reactivate for the textures
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
	{
		print_error_fd("ft_get_tex_img: invalide file", NULL, 2);
		return (1);
	}
	return (ret);
}
