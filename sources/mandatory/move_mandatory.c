/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:02 by agouet            #+#    #+#             */
/*   Updated: 2022/12/13 13:2 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// move = ne change pas  ma carte, met a jour les pixels
//cast de ma position => donne la case 
//deplacement x= x+move_speed => on multiplie par le vecteur dorientation 
//pour tenir compte des changement de rotattion
void	move(double new_pos_x, double new_pos_y, t_all *all)
{
	int		next_index;
	int		map_x;
	int		map_y;
	double	old_x;
	double	old_y;

	old_x = all->pos.p_x;
	old_y = all->pos.p_y;
	map_x = (int)(new_pos_x);
	map_y = (int)(new_pos_y);
	next_index = map_y * all->map.x + map_x;
	if (all->map.line[next_index] != '1')
		all->pos.p_x = new_pos_x;
	if (all->map.line[next_index] != '1')
		all->pos.p_y = new_pos_y;
}

void	rotate(t_all *all, int sign, double speed)
{
	double	old_orient_x;
	double	old_plane_x;

	old_orient_x = all->ray.orient_x;
	old_plane_x = all->ray.plane_x;
	all->ray.orient_x = all->ray.orient_x * cos(sign * speed)
		- all->ray.orient_y * sin(sign * speed);
	all->ray.plane_x = all->ray.plane_x * cos(sign * speed)
		- all->ray.plane_y * sin (sign * speed);
	all->ray.orient_y = old_orient_x * sin(sign * speed)
		+ all->ray.orient_y * cos(sign * speed);
	all->ray.plane_y = old_plane_x * sin(sign * speed)
		+ all->ray.plane_y * cos (sign * speed);
}
