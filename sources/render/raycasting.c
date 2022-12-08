/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:44:44 by lollith           #+#    #+#             */
/*   Updated: 2022/12/08 13:00:20 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculate distance projected on camera direction
//(Euclidean distance would give fisheye effect!)
// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe

//dist_perp evite le fisheye  
double	calcul_view(t_all *all)
{
	double	dist_perp;

	if (all->ray.side == 0)
		dist_perp = (all->ray.dist_x - all->ray.delta_dist_x);
	else
		dist_perp = (all->ray.dist_y - all->ray.delta_dist_y);
	all->ray.wall_height = (int)(W_HEIGHT / dist_perp);
	all->ray.draw_start = -all->ray.wall_height / 2 + W_HEIGHT / 2;
	if (all->ray.draw_start < 0)
		all->ray.draw_start = 0;
	all->ray.draw_end = all->ray.wall_height / 2 + W_HEIGHT / 2;
	if (all->ray.draw_end >= W_HEIGHT)
		all->ray.draw_end = W_HEIGHT - 1;
	return (dist_perp);
}

//wall_x = exact value of hit (on x or y)
void	tex_coord_x(t_all *all, double dist_perp)
{
	double	wall_x;

	if (all->ray.side == 0)
		wall_x = all->pos.p_y + dist_perp * all->ray.r_dir_y;
	else
		wall_x = all->pos.p_x + dist_perp * all->ray.r_dir_x;
	wall_x -= (int) wall_x;
	all->ray.tex_x = (int)(wall_x * all->tex[all->ray.dir_tex].width);
	if (all->ray.side == 0 && all->ray.r_dir_x > 0)
		all->ray.tex_x = all->tex[all->ray.dir_tex].width - all->ray.tex_x - 1;
	if (all->ray.side == 1 && all->ray.r_dir_y < 0)
		all->ray.tex_x = all->tex[all->ray.dir_tex].width - all->ray.tex_x - 1;
}

//ratio taille de texture \ taille ecran=> de cb augmenter ma texture 
// en fct de la taille de lecran
void	draw_wall(t_all *all, int x)
{
	int		color;
	int		y;
	int		index;
	double	ratio;
	double	tex_pos;

	ratio = (double)all->tex[all->ray.dir_tex].width / all->ray.wall_height;
	tex_pos = (all->ray.draw_start - W_HEIGHT / 2 + all->ray.wall_height / 2)
		* ratio;
	y = all->ray.draw_start;
	while (y < all->ray.draw_end)
	{
		all->ray.tex_y = (int) tex_pos;
		tex_pos += ratio;
		index = all->ray.tex_y * all->tex[all->ray.dir_tex].line_len
			+ all->ray.tex_x * all->tex[all->ray.dir_tex].bpp / 8;
		color = ((int *)all->tex[all->ray.dir_tex].addr)[index / 4];
		img_pix(&all->img_px, x, y, color);
		y++;
	}
}

// a garder de cote
void	draw_vert_wall(t_all *all, t_img *img, int x)
{
	int	y;
	int	color;

	color = BLUE;
	if (all->ray.side == 1)
		color = color / 2;
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
	int		x;
	int		map_x;
	int		map_y;
	double	dist_perp;

	x = 0;
	while (x < W_WIDTH)
	{
		ray_direction(all, &x);
		ray_size_in_square(all);
		dda_init(all, &map_x, &map_y);
		digital_differential_analysis(all, &map_x, &map_y);
		dist_perp = calcul_view(all);
		dir_tex(all);
		tex_coord_x(all, dist_perp);
		draw_wall(all, x);
		x++;
	}
}

// draw_vert_wall(all, &all->img_px, x);