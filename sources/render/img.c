/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:59:59 by lollith           #+#    #+#             */
/*   Updated: 2022/11/22 17:06:27 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void img_creation(t_all *all)
{
	// creation img minimap
	all->img_minimap.mlx_img = mlx_new_image(all->win.pt_mlx, W_WIDTH, W_HEIGHT);
	all->img_minimap.addr = mlx_get_data_addr(all->img_minimap.mlx_img, 
		&all->img_minimap.bpp, &all->img_minimap.line_len, &all->img_minimap.endian);
	// creation img personnage sur minimap

}