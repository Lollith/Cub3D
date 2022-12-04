/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/04 17:20:47 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_img_path(char *line, char **path, int *flag)
{
	int	i;

	i = 0;
	ft_skip(&line[i], &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_get_img_path: invalide file", NULL, 2);
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
	if (line[i] == 'N' && line[i + 1] == 'O')
		ret = ft_get_img_path(&line[i + 2], &all->tex[NORTH].dir, &all->flag);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ret = ft_get_img_path(&line[i + 2], &all->tex[SOUTH].dir, &all->flag);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ret = ft_get_img_path(&line[i + 2], &all->tex[WEST].dir, &all->flag);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		ret = ft_get_img_path(&line[i + 2], &all->tex[EAST].dir, &all->flag);
	else
	{
		print_error_fd("ft_get_tex_img: invalide file", NULL, 2);
		return (1);
	}
	// printf("here%s\n", all->tex[NORTH].dir); // boucle ??
	// printf("here%s\n", all->tex[SOUTH].dir);//
	return (ret);
}
