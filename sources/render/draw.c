/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/12/11 15:04:50 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_creation(t_all *all)
{
	all->img_px.mlx_img = mlx_new_image(all->win.pt_mlx,
			W_WIDTH, W_HEIGHT);
	all->img_px.addr = mlx_get_data_addr(all->img_px.mlx_img,
			&all->img_px.bpp, &all->img_px.line_len,
			&all->img_px.endian);
}

void	draw_rectangle(t_img *img, int position, unsigned int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			img_pix(img, x, y + position, color);
			x++;
		}
		y++;
	}
}

void	put_background(t_img *img, t_all *all)
{
	draw_rectangle(img, 0, all->img_px.c);
	draw_rectangle(img, W_HEIGHT / 2, all->img_px.f);
}
