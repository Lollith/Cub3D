/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_tex_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/12 14:01:56 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	ft_char_int(char *line, int *i, int *rgb)
{
	int	ret;

	ret = 0;
	if (line[*i] == '+')
		(*i)++;
	if (line[*i] < '0' || line[*i] > '9')
	{
		msg_err("ft_char_int: invalid color", line, 2);
		return (-1);
	}
	while (line[*i] >= '0' && line[*i] <= '9' && line[*i] != '\0')
	{
		ret = ret * 10 + line[*i] - '0';
		(*i)++;
	}
	if (ret < 0 || ret > 255)
	{
		msg_err("ft_char_int: invalid color (< 0 || > 255)", line, 2);
		return (-1);
	}
	*rgb = ret;
	return (0);
}

static int	ft_get_rgb_color(char *line, int *i, unsigned int *color)
{
	int	rgb[3];
	int	j;

	j = 0;
	while (j < 3)
	{
		ft_skip(line, i);
		if (ft_char_int(line, i, &rgb[j]) == -1)
			return (-1);
		ft_skip(line, i);
		if (j < 2 && line[*i] != ',')
		{
			msg_err("ft_get_rgb_color: invalid color 1", line, 2);
			return (-1);
		}
		if (j == 2 && line[*i] != '\0')
		{
			msg_err("ft_get_rgb_color: invalid color 2", line, 2);
			return (-1);
		}
		j++;
		(*i)++;
	}
	*color = ft_create_rgb(rgb[0], rgb[1], rgb[2]);
	return (0);
}

static int	ft_get_color(unsigned int *color, char *line, int *i, int *flag)
{
	(*i)++;
	if (line[*i] != ' ')
		return (msg_err("ft_get_color: invalid color", line, 2));
	else if (ft_get_rgb_color(line, i, color) == -1)
		return (1);
	(*flag)++;
	return (0);
}

int	ft_get_tex_color(char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (line[i] == 'F' && all->img_px.f == 0)
		ret = ft_get_color(&all->img_px.f, &line[i], &i, &all->flag);
	else if (line[i] == 'C' && all->img_px.c == 0)
		ret = ft_get_color(&all->img_px.c, &line[i], &i, &all->flag);
	return (ret);
}
