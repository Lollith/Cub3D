/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:44:44 by lollith           #+#    #+#             */
/*   Updated: 2022/12/06 20:50:09 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculate distance projected on camera direction
//(Euclidean distance would give fisheye effect!)
// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe

//dist_perp evite le fisheye  
int	calcul_view(t_all *all, int *side, int x)
{
	double	dist_perp;
	int		wall_height;

	if (*side == 0)
		dist_perp = (all->ray.dist_x - all->ray.delta_dist_x);
	else
		dist_perp = (all->ray.dist_y - all->ray.delta_dist_y);
	wall_height = (int)(W_HEIGHT / dist_perp);
	all->ray.draw_start = - wall_height / 2 + W_HEIGHT / 2;
	if (all->ray.draw_start < 0)
		all->ray.draw_start = 0;
	all->ray.draw_end = wall_height / 2 + W_HEIGHT / 2;
	if (all->ray.draw_end >= W_HEIGHT)
		all->ray.draw_end = W_HEIGHT - 1;

	//---------------------------------------
//calcul texture
	double wall_x;// exact value hit
	if (*side == 0)
		wall_x = all->pos.p_y + dist_perp * all->ray.r_dir_y;
	else
		wall_x = all->pos.p_x + dist_perp * all->ray.r_dir_x;
	wall_x -= (int) wall_x; // fct floor??

		//x coordinate de la texture
		int tex_x = (int)(wall_x * TEX_SIZE);
		if(*side == 0 && all->ray.r_dir_x > 0)
			tex_x = TEX_SIZE - tex_x -1;
		if (*side == 1 && all->ray.r_dir_y < 0)
			tex_x = TEX_SIZE -tex_x -1;
		
	// 	//ratio taille de texture \ taille ecran=> de cb augmenter ma texture 
	// 	// en fct de la taille de lecran
		double ratio  =  (double)TEX_SIZE / wall_height;
		double tex_pos = (all->ray.draw_start - W_HEIGHT / 2 + wall_height / 2 ) * ratio;
		for (int y = all->ray.draw_start; y < all->ray.draw_end; y++)
		{
			int tex_y = (int) tex_pos;
			tex_pos += ratio;
			all->img_px.addr[y * all->img_px.line_len + x * all->img_px.bpp /8] = all->tex[0].addr[tex_y * all->tex[0].line_len  + tex_x * all->tex[NORTH].bpp /8];
			// printf("%d\n", all->tex[0].bpp);
		}

	return 0;// a suprimer
}

void	draw_vert_wall(t_all *all, t_img *img, int x, int color)
{
	int	y;

	y = all->ray.draw_start;
		while (y < all->ray.draw_end)
		{
			img_pix(img, x, y, color);
			y++;
		}
}

// fov = 60 , tan(60/2)=  oppose/adj
// lenght_plane = W_WiDTH
// ratioX = cameraX
void	raycasting(t_all *all)
{
	int	x;
	int	map_x;
	int	map_y;
	int	side;

	x = 0;
	while (x < W_WIDTH)
	{
		ray_direction(all, &x);
		ray_size_in_square(all);
		dda_init(all, &map_x, &map_y);
		digital_differential_analysis(all, &map_x, &map_y, &side);
		calcul_view(all, &side, x);
//------------------------------------------------------------------------------
		// a remplacer par texture
		// give x and y sides different brightness
		// draw the pixels of the stripe as a vertical line

	
//---------------------------------------------- --------------------------------		
// a garder de coter
		// color = BLUE;
		// if (side == 1)
			// color = color / 2;
		// draw_vert_wall(all, &all->img_px, x, color);
//------------------------------------------------------------------------------//
		x++;
	}
}
