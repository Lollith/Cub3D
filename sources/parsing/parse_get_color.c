/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/07 14:11:00 by esmirnov         ###   ########.fr       */
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
		if (line[j] < '0' || line[j] > '9')
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

static int	ft_get_rgb_color(char *line, int *i, unsigned int *color)
{
	int	r;
	int	g;
	int	b;

	r = ft_char_int(&line[*i], i);
	if (r == -1)
		return (1);
	g = ft_char_int(&line[*i], i);
	if (g == -1)
		return (1);
	b = ft_char_int(&line[*i], i);
	if (b == -1)
		return (1);
	*color = ft_create_rgb(r, g, b);
	return (0);
}

static int	ft_get_color(unsigned int *color, char *line, int *flag)
{
	int	i;

	i = 0;
	if (line[i] != ' ')
	{
		print_error_fd("ft_get_color: invalide color description", NULL, 2);
		return (1);
	}
	ft_skip(line, &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_put_color: invalide color description", NULL, 2);
		return (1);
	}
	if (ft_get_rgb_color(&line[i], &i, color) == 1)
		return (1);
	(*flag)++;
	return (0);
}

int	ft_get_tex_color(char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	if (line[i] == 'F' && all->img_px.f == 0)
		ret = ft_get_color(&all->img_px.f, &line[i + 1], &all->flag);
	else if (line[i] == 'C' && all->img_px.c == 0)
		ret = ft_get_color(&all->img_px.c, &line[i + 1], &all->flag);
	else
	{
		print_error_fd("ft_get_tex_color: invalide file", NULL, 2);
		return (1);
	}
	return (ret);
}
