/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:44:44 by lollith           #+#    #+#             */
/*   Updated: 2022/12/02 14:35:23 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Calculate distance projected on camera direction
//(Euclidean distance would give fisheye effect!)
// Calculate height of line to draw on screen
// calculate lowest and highest pixel to fill in current stripe

//dist_perp evite le fisheye  
void	calcul_view(t_all *all, int *side)
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
}

void	draw_vert_wall(t_all *all, t_img *img, int x, int color)
{
	int	y;

	y = all->ray.draw_start;
	{
		while (y < all->ray.draw_end)
		{
			img_pix(img, x, y, color);
			y++;
		}
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
		calcul_view(all, &side);
//------------------------------------------------------------------------------
		// a remplacer par texture
		// give x and y sides different brightness
		int color = BLUE;
		if (side == 1)
			color = color / 2;
		// draw the pixels of the stripe as a vertical line
//------------------------------------------------------------------------------		
		draw_vert_wall(all, &all->img_px, x, color);
		x++;
	}
}
