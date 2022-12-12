/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_px.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:59:59 by lollith           #+#    #+#             */
/*   Updated: 2022/12/12 09:25:17 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// creer une string de pixel
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

//boucle : map+1 rempli du debut et jusquq 1 caree de Mini_cub
//y + mini_pos = place la minimap en bas de lecran
void	draw_mini_wall(int *pt_i, t_img *img, t_all *all, int color)
{
	int	x;
	int	y;
	int	i;

	i = *pt_i;
	y = i / (all->map.x) * MINI_CUB;
	while (y < (i / all->map.x + 1) * MINI_CUB)
	{
		x = (i % (all->map.x) * MINI_CUB);
		while (x < (i % all->map.x + 1) * MINI_CUB)
		{
			img_pix(img, x, y + all->map.mini_pos, color);
			x++;
		}
		y++;
	}
}

	// pointe direction
void	draw_heroe_dir_n_s(t_img *img, t_all *all)
{
	double	y;
	double	x;

	if (all->pos.p == 'N')
	{
		x = (all->pos.p_x + 0.1) * MINI_CUB;
		y = (all->pos.p_y) * MINI_CUB;
		while ((x < (all->pos.p_x + 0.2) * MINI_CUB))
		{
			img_pix(img, x, y -0.1 + all->map.mini_pos, YELLOW);
			x++;
		}
	}
	if (all->pos.p == 'S')
	{
		x = (all->pos.p_x + 0.1) * MINI_CUB;
		y = (all->pos.p_y + MINI_P) * MINI_CUB;
		while ((x < (all->pos.p_x + 0.2) * MINI_CUB))
		{
			img_pix(img, x, y + 0.1 + all->map.mini_pos, YELLOW);
			x++;
		}
	}
}

void	draw_heroe_dir_w_e(t_img *img, t_all *all)
{
	double	y;
	double	x;

	if (all->pos.p == 'W')
	{
		x = (all->pos.p_x) * MINI_CUB;
		y = (all->pos.p_y + 0.1) * MINI_CUB;
		while ((y < (all->pos.p_y + 0.2) * MINI_CUB))
		{
			img_pix(img, x - 0.1, y + all->map.mini_pos, YELLOW);
			y++;
		}
	}
	if (all->pos.p == 'E')
	{
		x = (all->pos.p_x + MINI_P) * MINI_CUB;
		y = (all->pos.p_y + 0.1) * MINI_CUB;
		while ((y < (all->pos.p_y + 0.2) * MINI_CUB))
		{
			img_pix(img, x + 0.1, y + all->map.mini_pos, YELLOW);
			y++;
		}
	}
}

// size of heroe on minimap = MINI_P
// pos.p_x et y se mette a jour a linitialisation puis en fct des mouvement
// la boucle de render permet de faire avancer le personnage
void	draw_heroe(t_img *img, t_all *all)
{
	double	y;
	double	x;

	y = (all->pos.p_y) * MINI_CUB;
	while ((y < (all->pos.p_y + MINI_P) * MINI_CUB))
	{
		x = (all->pos.p_x) * MINI_CUB;
		while (x < ((all->pos.p_x + MINI_P) * MINI_CUB))
		{
			img_pix(img, x, y + all->map.mini_pos, YELLOW);
			x++;
		}
		y++;
	}
	draw_heroe_dir_n_s(img, all);
	draw_heroe_dir_w_e(img, all);
}
