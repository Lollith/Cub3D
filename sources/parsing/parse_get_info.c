/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:18:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/25 14:49:02 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_tex_color(t_texture *tex, char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	if (line[i] == 'F')
		ret = ft_get_color(&tex->f, &line[i + 1], &all->flag);
	else
		ret = ft_get_color(&tex->c, &line[i + 1], &all->flag);
	return (ret);
}

int	ft_get_img_path(char *line, char *path, int *flag)
{
	int	i;

	i = 0;
	ft_skip(line, &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_put_tex_img: invalide file", NULL, 2);
		return (1);
	}
	path = ft_strdup(&line[i]);
	if (path == NULL)
		return (1);
	(*flag)++;
	return (0);
}

int	ft_get_tex_img(t_texture *tex, char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O')
		ret = ft_get_img_path(&line[i + 2], tex->n, &all->flag);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ret = ft_get_img_path(&line[i + 2], tex->s, &all->flag);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ret = ft_get_img_path(&line[i + 2], tex->w, &all->flag);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		ret = ft_get_img_path(&line[i + 2], tex->e, &all->flag);
	else
	{
		print_error_fd("ft_get_tex_img: invalide file", NULL, 2);
		return (1);
	}
	return (ret);
}

static int	ft_get_tex_map(char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	ft_skip(&line[i], &i);
	if (all->flag < 6)
	{
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			ret = ft_get_tex_img(&all->tex, &line[i], all);
		else if (line[i] == 'F' || line[i] == 'C')
			ret = ft_get_tex_color(&all->tex, &line[i], all);
	}
	else if (line[i] == '\0')
		return (0);
	else if (line[i] == '1' && all->flag >= 6)
	{
		// ret = ft_get_map();
	}
	else
	{
		print_error_fd("ft_get_tex_map: invalide file", NULL, 2);
		return (1);
	}
	return (ret);
}

int	ft_get_info(char *av, t_all *all)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
	{
		print_error_fd("ft_get_tex_map: invalid fd", NULL, 2);
		return (1);
	}
	line = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL) // a confirmer avec Adeline EOF => NULL et erreur NULL
			break ;
		if (ft_get_tex_map(line, all) == 1)
		{
			free(line);
			close (fd);
			return (1);
		}
		free (line);
	}
	close (fd);
	return (0);
}
