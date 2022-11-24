/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:19:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/24 20:41:52 by esmirnov         ###   ########.fr       */
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

int	ft_get_rgb(unsigned int *color, char *line, int *flag)
{
	int	r;
	int	g;
	int	b;
	int	i;

	i = 0;
	ft_skip(line, &i);
	if (line == NULL || line[i] == '\0')
	{
		print_error_fd("ft_put_color: invalide color", NULL, 2);
		return (1);
	}
	while(line[i] >= '0' && line[i] <= '9')
	{
		r = atoi()
		
	}
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}
