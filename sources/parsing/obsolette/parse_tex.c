/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:30:34 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/24 16:44:05 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_put_color(unsigned int *color, char *line, int *flag)
{
	int	i;

	(void)color;
	(void)flag;
	i = 0;
	ft_skip(line, &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_put_color: invalide color", NULL, 2);
		return (1);
	}
	// color = ft_color_convert(line);
	return (0);
}

int	ft_texture_color(t_texture *tex, char **doc, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (doc[i])
	{
		j = 0;
		ft_skip(doc[i], &j);
		if ((doc[i][j] == 'F'))
			ft_put_color(&tex->f, &doc[i][j + 2], &all->flag);
		else if (doc[i][j] == 'C')
			ft_put_color(&tex->c, &doc[i][j + 2], &all->flag);
		else if (doc[i][j] == '1' && all->flag < 6)
		{
			print_error_fd("ft_texture_color: map before elements", NULL, 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_put_tex(t_texture *tex, char *line, int *path, int *flag)
{
	return (0);
}

// int	ft_texture_images(t_texture *tex, char **doc, t_all *all)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (doc[i])
// 	{
// 		j = 0;
// 		ft_skip(doc[i], &j);
// 		if (doc[i][j] == 'N' && doc[i][j + 1] == 'O')
// 			ft_put_tex(tex, &doc[i][j + 2], tex->n, &all->flag);
// 		else if (doc[i][j] == 'S' && doc[i][j + 1] == 'O')
// 			ft_put_tex(tex, &doc[i][j + 2], tex->s, &all->flag);
// 		else if (doc[i][j] == 'W' && doc[i][j + 1] == 'E')
// 			ft_put_tex(tex, &doc[i][j + 2], tex->w, &all->flag);
// 		else if (doc[i][j] == 'E' && doc[i][j + 1] == 'A')
// 			ft_put_tex(tex, &doc[i][j + 2], tex->e, &all->flag);
// 		else if (doc[i][j] == '1' && all->flag < 6)
// 		{
// 			print_error_fd("ft_texture_images: map before elements", NULL, 2);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_texture(t_texture *tex, char **doc, t_all *all)
// {
// 	if (ft_texture_images(tex, doc, all) == 1)
// 		return (1);
// 	// if (check_texture_image == 1)
// 	// 	return (1);
// 	if (ft_texture_color(tex, doc, all) == 1)
// 		return (1);
// 	return (0);
// }
