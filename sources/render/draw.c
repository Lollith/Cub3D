/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:10:04 by lollith           #+#    #+#             */
/*   Updated: 2022/11/18 15:07:52agouet           ###   ########.fr       */
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
	int	i;
	int j;
	int wall;
	wall = 0;

	while (all->map.line[wall])
	{
			if ( all->map.line[wall] == '1')
			{
				i = wall /5 *20;
			 	while (i < ((wall / 5) + 1)  * 20 )
	 		 	{
					j = wall % 5 * 20;
					while (j < ((wall % 5 ) + 1) * 20)
					{
						img_pix(img, j , i, 0xFF0000);
						j ++;
					}
					i++;
				}
			}
			wall++;
	}
	return (0);
}

int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	wall_px(&all->img, all); // crrer une minimap
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
			all->img.mlx_img, 0, 0);
	return (0);
}
