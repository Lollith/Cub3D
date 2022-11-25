/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:59:59 by lollith           #+#    #+#             */
/*   Updated: 2022/11/25 13:59: by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// creation img minimap
void img_creation(t_all *all)
{
	all->img_minimap.mlx_img = mlx_new_image(all->win.pt_mlx,
											 W_WIDTH, W_HEIGHT);
	all->img_minimap.addr = mlx_get_data_addr(all->img_minimap.mlx_img,
											  &all->img_minimap.bpp, &all->img_minimap.line_len,
											  &all->img_minimap.endian);
}

// point de pixels rouge
void img_pix(t_img *img, int x, int y, int color)
{
	char *pixel;
	int i;

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

void draw_wall(int *pt_i, t_img *img, t_all *all, int color)
{
	int x;
	int y;
	int i;

	i = *pt_i;
	y = i / (all->map.x + 1) * MINI_CUB;
	while (y < (i / (all->map.x + 1) + 1) * MINI_CUB)
	{
		x = (i % (all->map.x + 1) * MINI_CUB);
		while (x < (i % (all->map.x + 1) + 1) * MINI_CUB)
		{
			img_pix(img, x, y  + all->map.mini_pos, color);
			x++;
		}
		y++;
	}
} // y +... // met la minimap en bas

// size of heroe on minimap = MINI_P
// pos.p_x et y se mette a jour a linitialisation puis en fct des mouvement
// la boucle de render permet de faire avancer le personnage
void draw_heroe(t_img *img, t_all *all)
{
	double y;
	double x;

	y = all->pos.p_y * MINI_CUB;
	while ((y < (all->pos.p_y + MINI_P) * MINI_CUB))
	{
		x = all->pos.p_x * MINI_CUB;
		while (x < ((all->pos.p_x + MINI_P) * MINI_CUB))
		{
			img_pix(img, x, y + all->map.mini_pos, 0xFFFFFF00);
			x++;
		}
		y++;
	}
}

// ne calcul pas la bonne taile du rayon=> l arretr moi meme au mur
void draw_ray(t_img *img, t_all *all)
{
	double	x;
	double	y;
	// if (all->ray.sideDistX > all->map.x * MINI_CUB)
	// 	all->ray.sideDistX = all->map.x +5 ; // fire plus joli
	// if (all->ray.sideDistY > all->map.x * MINI_CUB)
	// 	all->ray.sideDistY = all->map.y + 5; // normale;emt pas besoin doit calculer la bonne taille du mur , pb si ray dir = 0 = prend la valeur infinie
	y = all->ray.step_y *(all->pos.p_y + MINI_P/2)* MINI_CUB;
	x = all->ray.step_x * (all->pos.p_x +  MINI_P/2 )* MINI_CUB;
	 img_pix(img, all->ray.step_x* (x + MINI_P), all->ray.step_y * (y+ MINI_P)+ all->map.mini_pos, 0xF00020);
	while ( y < (all->pos.p_y * MINI_CUB + all->ray.sideDistY) && x < (all->pos.p_x * MINI_CUB+ all->ray.sideDistX))
	{
		// img_pix(img, x, y, 0xFFFFFF00);
		
		img_pix(img,  all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P) + all->map.mini_pos, 0xFFFFFF00);
		x++;
		y++;
	}

}

// draw avec ray dir ++ arreter le rayon  a la main// marche pas 
// void draw_ray(t_img *img, t_all *all)
// {
// 	double x;
// 	double y;
// 	// y = (all->pos.p_y + MINI_P / 2) * MINI_CUB;
// 	// x = all->pos.p_x * MINI_CUB + MINI_P / 2 * MINI_CUB;
// 	y = all->ray.step_y *(all->pos.p_y + MINI_P/2)* MINI_CUB;
//  	x = all->ray.step_x * (all->pos.p_x +  MINI_P/2 )* MINI_CUB;
// 	img_pix(img, all->ray.step_x* (x + MINI_P), all->ray.step_y * (y+ MINI_P), 0xF00020);
	
// 	while ( y < (all->pos.p_y * MINI_CUB + fabs(all->ray.r_dir_y) * MINI_CUB) && x < (all->pos.p_x * MINI_CUB+ fabs(all->ray.r_dir_x )* MINI_CUB))
// 	{
// 		img_pix(img,  all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P) , 0xFFFFFF00);
// 		x++;
// 		y++;
// 	}
// }

// nettoie les pixels laisser par le heroe=> en noir
void clean_px(t_img *img, t_all *all)
{
	int z;
	int w;

	if ((int)all->pos.old_p_x != 0 && (int)all->pos.old_p_y != 0)
	{
		z = all->pos.old_p_y * MINI_CUB - MINI_P;
		while ((z < (all->pos.index / (all->map.x + 1) + MINI_P) * MINI_CUB))
		{
			w = (int)all->pos.old_p_x * MINI_CUB + MINI_P;
			while (w < ((all->pos.index % (all->map.x + 1) + MINI_P) * MINI_CUB))
			{
				img_pix(img, w, z + all->map.mini_pos, 0x00000000); //+ mini po pour redescendre la carte en bas
				w++;
			}
			z++;
		}
	}
}
