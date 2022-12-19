/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/12/17 10:27:59 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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

// creer une minimap , map.x = longueur de la map sur x
void	put_minimap(t_img *img, t_all *all)
{
	int	i;

	all->map.mini_pos = W_HEIGHT - all->map.y * MINI_CUB;
	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == '1')
			draw_mini_wall(&i, img, all, GREY);
		if (all->map.line[i] != ' ' && all->map.line[i] != '\n'
			&& all->map.line[i] != '1')
			draw_mini_wall(&i, img, all, TBLACK);
		i++;
	}
}
