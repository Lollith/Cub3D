/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:45:55 by lollith           #+#    #+#             */
/*   Updated: 2022/12/01 19:10:53 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// orient_ : N S E W
// calcul de la direction du rayon = vecteur dir + ratio du plan
void	ray_direction(t_all *all, int *pt_x)
{
	double	ratio;
	int		x;

	x = *pt_x;
	ratio = 2 * (x) / (double)W_WIDTH - 1;
	all->ray.r_dir_x = all->ray.orient_x + all->ray.plane_x * ratio;
	all->ray.r_dir_y = all->ray.orient_y + all->ray.plane_y * ratio;
	pt_x = &x;
}

void	ray_size_in_square(t_all *all)
{
	if (all->ray.r_dir_x == 0)
		all->ray.delta_dist_x = 1e30;
	else
		all->ray.delta_dist_x = fabs(1 / all->ray.r_dir_x);
	if (all->ray.r_dir_y == 0)
		all->ray.delta_dist_y = 1e30;
	else
		all->ray.delta_dist_y = fabs(1 / all->ray.r_dir_y);
}

// mapX  which box of the map we're in =>cast la pos
//  calculate step and initial sideDist = dist_
//  what direction to step in x or y-direction (either +0 or -1)
//  pos + -1.2 avance un peu mon perso sur la case
void	dda_init(t_all *all, int *map_x, int *map_y)
{
	// posX = all->pos.p_x + 0.2;  check si minimap ok avec linitialisation
	// posY = all->pos.p_y + 0.2;
	*map_x = (int)all->pos.p_x;
	*map_y = (int)all->pos.p_y;
	if (all->ray.r_dir_x < 0)
	{
		all->ray.step_x = -1;
		all->ray.dist_x = (all->pos.p_x - *map_x) * (all->ray.delta_dist_x);
	}
	else
	{
		all->ray.step_x = 1;
		all->ray.dist_x = (*map_x + 1.0 - all->pos.p_x) * all->ray.delta_dist_x;
	}
	if (all->ray.r_dir_y < 0)
	{
		all->ray.step_y = -1;
		all->ray.dist_y = (all->pos.p_y - (*map_y)) * (all->ray.delta_dist_y);
	}
	else
	{
		all->ray.step_y = 1;
		all->ray.dist_y = (*map_y + 1.0 - all->pos.p_y) * all->ray.delta_dist_y;
	}
}

// hit was there a wall hit?
// side was a NS or a EW wall hit?
// jump to next map square, either in x-direction, or in y-direction
// Check if ray has hit a wall
void	digital_differential_analysis(t_all *a, int *mapx, int *mapy, int *side)
{
	int	hit;
	int	index;

	hit = 0;
	while (hit == 0)
	{
		if (a->ray.dist_x < a->ray.dist_y)
		{
			a->ray.dist_x += a->ray.delta_dist_x;
			(*mapx) += a->ray.step_x;
			(*side) = 0;
		}
		else
		{
			a->ray.dist_y += a->ray.delta_dist_y;
			(*mapy) += a->ray.step_y;
			*side = 1;
		}
		index = (*mapy) * (a->map.x) + (*mapx);
		if (a->map.line[index] == '1')
			hit = 1;
	}
}