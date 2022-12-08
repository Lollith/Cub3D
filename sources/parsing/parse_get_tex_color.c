/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_tex_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/08 21:05:13 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

// static unsigned int	ft_create_rgb(int *rgb)
// {
// 	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
// }

static int	ft_char_int(char *line, int *i)
{
	int	j;
	int	ret;

	j = 0;
	ret = 0;
	printf("line[%d] = %c\n", *i, line[*i]);
	while (line[*i] >= '0' && line[*i] <= '9' && line[*i] !='\0')
	{
		printf("char int line[%d] = %c\n", *i, line[*i]);
		printf("j = %d\n", j);
		if (line[*i] < '0' || line[*i] > '9')
		{
			msg_err("ft_char_int: invalide color number 1 ", NULL, 2);
			return (-1);
		}
		ret = ret * 10 + line[*i] - '0';
		j++;
		(*i)++;
	}
	ft_skip(line, i);
	if ( line[*i] == ',')
		(*i)++;
	printf("ret = %d\n", ret);
	if (ret < 0 || ret > 255)
	{
		msg_err("ft_char_int: invalide color number 2", NULL, 2);
		return (-1);
	}
	// ft_skip(line, i);
	// if (line[j] != ',')// to see for \n
	// {
	// 	msg_err("ft_char_int: invalide color description", NULL, 2);
	// 	return (-1);
	// }
	// // else
	// (*i)++;
	return (ret);
}

// static int	ft_get_rgb_color(char *line, int *i, unsigned int *color)
static int	ft_get_rgb_color(char *line, unsigned int *color)
{
	// int	r;
	// int	g;
	// int	b;
	int rgb[3];
	int	i;
	int j;

	j = 0;
	i = 0;
	while (j < 3)
	{
		printf("get rgb color - line[%d] = %c\n", i, line[i]);
		ft_skip(line, &i);
		printf("get rgb color - line[%d] = %c\n", i, line[i]);
		// if (line[i] == '\0' || line[i] > 9 || line[i] < 0)
		// {
		// 	msg_err("ft_char_int: invalide color description 1", NULL, 2);
		// 	return (-1);
		// }
		rgb[j] = ft_char_int(line, &i);
		if (rgb[j] == -1)
			return (1);

		printf("get rgb color - line[%d] = %c\n", i, line[i]);
		if (j < 2 && line[i] != ',')// to see for \n
		{
			msg_err("ft_char_int: invalide color description 2", NULL, 2);
			return (-1);
		}
		j++;
		i++;
	}
	// int count;

	// count = ft_scan_line(&line[*i]);
	// if (count < 0)
	// 	return (1);
	// ft_skip(line, i);//
	// r = ft_char_int(&line[*i], i);
	// if (r == -1)
	// 	return (1);
	// g = ft_char_int(&line[*i], i);
	// if (g == -1)
	// 	return (1);
	// b = ft_char_int(&line[*i], i);
	// if (b == -1)
	// 	return (1);
	*color = ft_create_rgb(rgb[0], rgb[1], rgb[2]);
	return (0);
}

// static int	ft_get_rgb_color(char *line, int *i, unsigned int *color)
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	// int count;

// 	// count = ft_scan_line(&line[*i]);
// 	// if (count < 0)
// 	// 	return (1);
// 	ft_skip(line, i);//
// 	r = ft_char_int(&line[*i], i);
// 	if (r == -1)
// 		return (1);
// 	g = ft_char_int(&line[*i], i);
// 	if (g == -1)
// 		return (1);
// 	b = ft_char_int(&line[*i], i);
// 	if (b == -1)
// 		return (1);
// 	*color = ft_create_rgb(r, g, b);
// 	return (0);
// }

static int	ft_get_color(unsigned int *color, char *line, int *flag)
{
	// int	i;

	// i = 0;
	// printf("line[%i] = %c\n", i, line[i]);
	// // ft_skip(line, &i);
	// printf("line[%i] = %c\n", i, line[i]);
	// if (line[i] == '\0')
	// 	return (msg_err("ft_get_color: invalid color", NULL, 2));
	// ft_skip(line, &i);//to check may be skip in RB color
	// if (ft_get_rgb_color(line, &i, color) == 1)
	if (ft_get_rgb_color(line, color) == 1)
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
		return (msg_err("ft_get_tex_color: invalid file", NULL, 2));
	return (ret);
}
