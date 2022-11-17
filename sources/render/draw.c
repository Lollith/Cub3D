/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:10:04 by lollith           #+#    #+#             */
/*   Updated: 2022/11/17 18:53:18 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// point de pixels rouge
void	img_pix_put(t_img *img, int x, int y, int color)
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

int	render_px(t_img *img)
{
	int	i;
	int	j;

	i = 30;
	while (i < 10 + 50)
	{
		j = 30;
		while (j < 10 + 50)
		{
			img_pix_put(img, j, i, 0xFF0000);
			j++;
		}
		i++;
	}
	return (0);
}

int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	render_px(&all->img);
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
		all->img.mlx_img, 0, 0);
	return (0);
}
