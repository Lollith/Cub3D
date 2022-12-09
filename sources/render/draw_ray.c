/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:28:03 by agouet            #+#    #+#             */
/*   Updated: 2022/12/09 16:15:03 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ne calcul pas la bonne taile du rayon=> l arretr moi meme au mur
// affichage dun rayon ds la bonne direction
void	draw_ray(t_img *img, t_all *all)
{
	double	x;
	double	y;
	(void) img;
	// double	l;
		
		x = (all->pos.p_x + MINI_P/2) * MINI_CUB;
		y = (all->pos.p_y + MINI_P/2) * MINI_CUB;
		double w = (all->pos.p_x + MINI_P/2) * MINI_CUB;
		double z = (all->pos.p_y + MINI_P/2) * MINI_CUB;
		// img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y+ MINI_P)+ all->map.mini_pos, 0xF00020);
		while (y < ((all->pos.p_y + all->ray.dist_y - 1)*MINI_CUB)
			&& x < ((all->pos.p_x + all->ray.dist_x - 1)* MINI_CUB))
		{
			// img_pix(img,x, y+ all->map.mini_pos, RED);
				img_pix(&all->img_px,x ,y + all->map.mini_pos , RED);
				img_pix(&all->img_px,w ,z + all->map.mini_pos , RED);
				
			x = x + all->ray.step_x * 1;
			y = y + all->ray.step_y * 1;
			w = w - all->ray.step_x * cos(  0.6);
			z = z - all->ray.step_y *sin ( 0.6);
		}
}

	//ancienne version
	// l = 0;
	// while (l < 20) // l doit etre inf a taille de la map * minicub - pos du perso, x?
	// {
	// 	y = all->ray.step_y * (all->pos.p_y + MINI_P / 2) * MINI_CUB;
	// 	x = all->ray.step_x * (all->pos.p_x + MINI_P / 2) * MINI_CUB;
	// 	// img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y+ MINI_P)+ all->map.mini_pos, 0xF00020);
	// 	while (y < ((all->pos.p_y + MINI_P / 2 + all->ray.dist_y) * MINI_CUB)
	// 		&& x < ((all->pos.p_x + MINI_P / 2 + all->ray.dist_x) * MINI_CUB))
	// 	{
	// 		img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P) + all->map.mini_pos, RED);
	// 		// img_pix(img, all->ray.step_x * (x + MINI_P )  , all->ray.step_y * (y + MINI_P+ l)  + all->map.mini_pos, 0xFFFF00FF);
	// 		x++;
	// 		y++;
	// 	}
	// 	l++;
	// }
// 	// rayon dans lautre sens pour cone FOV
// 	l = 0;
// 	while (l < 10) // l doit etre inf a taille de la map * minicub - pos du perso, x?
// 	{
// 		y = all->ray.step_y * (all->pos.p_y + MINI_P / 2) * MINI_CUB;
// 		x = all->ray.step_x * (all->pos.p_x + MINI_P / 2 ) * MINI_CUB;
// 		// while (y < (all->pos.p_y * MINI_CUB + all->ray.sideDistY)
// 			// && x < (all->pos.p_x * MINI_CUB + all->ray.sideDistX))
// 		while (y < ((all->pos.p_y + MINI_P / 2 + all->ray.dist_y) * MINI_CUB)
// 			&& x < ((all->pos.p_x + MINI_P / 2 + all->ray.dist_x) * MINI_CUB))
// 		{
// 			img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P /*+ l*/) + all->map.mini_pos, RED);
// 			x--;
// 			y++;
// 		}
// 		l++;
// 	}
// }

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
