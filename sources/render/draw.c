/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/11/20 20:28:36 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// point de pixels rouge
void	img_pix(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

// creer une minimap
int	wall_px(t_img *img, t_all *all)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == '1')
		{
			y = i / (all->map.x + 1) * MINI_SQUARE;
			while (y < (i / (all->map.x + 1) + 1) * MINI_SQUARE)
			{
				x = i % (all->map.x + 1) * MINI_SQUARE;
				while (x < ((i % (all->map.x + 1)) + 1) * MINI_SQUARE)
				{
					img_pix(img, x, y, 0xFF0000);
					x++;
				}
				y++;
			}
		}
		i++;
	}
	return (0);
}

int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	wall_px(&all->img_minimap, all); // creer une minimap
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
		all->img_minimap.mlx_img, 0, 0);// affiche l image
	return (0);
}
