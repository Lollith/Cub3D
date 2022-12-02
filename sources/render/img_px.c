/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_px.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:59:59 by lollith           #+#    #+#             */
/*   Updated: 2022/12/02 14:13:55 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// creation img minimap
void	img_creation(t_all *all)
{
	all->img_px.mlx_img = mlx_new_image(all->win.pt_mlx,
			W_WIDTH, W_HEIGHT);
	all->img_px.addr = mlx_get_data_addr(all->img_px.mlx_img,
			&all->img_px.bpp, &all->img_px.line_len,
			&all->img_px.endian);
}

// point de pixels rouge
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
void	draw_wall(int *pt_i, t_img *img, t_all *all, int color)
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
}

// ne calcul pas la bonne taile du rayon=> l arretr moi meme au mur
// affichage dun rayon ds la bonne direction
void	draw_ray(t_img *img, t_all *all)
{
	double	x;
	double	y;
	// double	l;
		
		y = (all->pos.p_y + MINI_P / 2) * MINI_CUB;
		x = (all->pos.p_x + MINI_P / 2) * MINI_CUB;
		// img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y+ MINI_P)+ all->map.mini_pos, 0xF00020);
		while (y < ((all->pos.p_y + MINI_P / 2 + all->ray.dist_y)* MINI_CUB)
			&& x < ((all->pos.p_x + MINI_P / 2 + all->ray.dist_x))* MINI_CUB)
		{
			img_pix(img,x + MINI_P, y + MINI_P + all->map.mini_pos, RED);
			// img_pix(img, all->ray.step_x * (x + MINI_P )  , all->ray.step_y * (y + MINI_P+ l)  + all->map.mini_pos, 0xFFFF00FF);
			x = x + (1/all->ray.r_dir_x);// ratio defini la direction de mon x en fct de ce ratio
			y = y + (1/all->ray.r_dir_y);
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
