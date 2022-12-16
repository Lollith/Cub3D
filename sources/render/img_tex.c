/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:33:33 by agouet            #+#    #+#             */
/*   Updated: 2022/12/16 12:49:50 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tex_creation(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		all->tex[i].img = mlx_xpm_file_to_image(all->win.pt_mlx,
				all->tex[i].dir, &all->tex[i].width, &all->tex[i].height);
		if (all->tex[i].width != all->tex[i].height)
			return (msg_err("Invalid texture", NULL, 2));
		if (all->tex[i].img == NULL)
			return (msg_err("Can't create image from texture", NULL, 2));
		all->tex[i].addr = mlx_get_data_addr(all->tex[i].img,
				&all->tex[i].bpp, &all->tex[i].line_len,
				&all->tex[i].endian);
		i++;
	}
	return (0);
}

void	ft_distroy_tex(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (all->tex[i].img != NULL)
			mlx_destroy_image(all->win.pt_mlx, all->tex[i].img);
		i++;
	}
}
