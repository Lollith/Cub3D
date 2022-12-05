/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/05 11:18:35 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	ft_char_int(char *line, int *i)
{
	int	j;
	int	ret;

	j = 0;
	ret = 0;
	while (line[j] != '\n' && line[j] != ',' && j < 3)
	{
		if (line [j] < '0' || line[j] > '9')
		{
			print_error_fd("ft_char_int: invalide color number", NULL, 2);
			return (-1);
		}
		ret = ret * 10 + line[j] - '0';
		j++;
		(*i)++;
	}
	if (line[j] != ',' && line[j] != '\n')
	{
		print_error_fd("ft_char_int: invalide color description", NULL, 2);
		return (-1);
	}
	else
		(*i)++;
	return (ret);
}

static int	ft_get_color(unsigned int *color, char *line, int *flag)
{
	int				r;
	int				g;
	int				b;
	int				i;

	i = 0;
	ft_skip(line, &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_put_color: invalide color description", NULL, 2);
		return (1);
	}
	r = ft_char_int(&line[i], &i);
	g = ft_char_int(&line[i], &i);
	b = ft_char_int(&line[i], &i);
	if (r == -1 || g == -1 || b == -1)
		return (1);
	*color = ft_create_rgb(r, g, b);
	(*flag)++;
	return (0);
}

int	ft_get_tex_color(char *line, t_all *all)
{
	int	i;
	int	ret;
	
	i = 0;
	if (line[i] == 'F')
		ret = ft_get_color(&all->img_px.f, &line[i + 1], &all->flag);
	else
		ret = ft_get_color(&all->img_px.c, &line[i + 1], &all->flag);
	return (ret);
}
