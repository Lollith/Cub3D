/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/25 14:13:44 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_create_rgb(unsigned char r, unsigned char g, unsigned char b)
// {
// 	return (*(int *)(unsigned char [4]){b, g, r, t});
// }

// unsigned char	get_t(int trgb)
// {
// 	return (((unsigned char *)&trgb)[3]);
// }

// unsigned char	get_r(int trgb)
// {
// 	return (((unsigned char *)&trgb)[2]);
// }

// unsigned char	get_g(int trgb)
// {
// 	return (((unsigned char *)&trgb)[1]);
// }

// unsigned char	get_b(int trgb)
// {
// 	return (((unsigned char *)&trgb)[0]);
// }

static unsigned int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	ft_char_int(char *line,int *i)
{
	int	j;
	int	ret;
	
	j = 0;
	ret = 0;
	while(line[j] != '\n' && line[j] != ',' && j < 3)
	{
		printf("line[%d] = %c, len is %lu\n", j, line[j], strlen(&line[j]));//to be deleted
		if (line [j] < '0' || line[j] > '9')
		{
			print_error_fd("ft_char_int: invalide color number", NULL, 2);
			return (-1);
		}
		ret = ret * 10 + line[j] - '0';
		j++;
		(*i)++;
	}
	printf("ret = %d\n", ret);//to be deleted
	if (line[j] != ',' && line[j] != '\n')
	{
		print_error_fd("ft_char_int: invalide color description", NULL, 2);
		return (-1);
	}
	else
		(*i)++;
	return (ret);
}

int	ft_get_color(unsigned int *color, char *line, int *flag)
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
	printf("R\n");
	r = ft_char_int(&line[i], &i);
	printf("G\n");
	g = ft_char_int(&line[i], &i);
	printf("B\n");
	b = ft_char_int(&line[i], &i);
	if (r == -1 || g == -1 || b == -1)
		return (1);
	*color = ft_create_rgb(r, g, b);
	(*flag)++;
	printf("ret %u\n", *color);
	return (0);
}
