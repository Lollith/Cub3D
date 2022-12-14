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
//gestion colision =)
// // faire pour x et y => plus precis
void	check_collision2(t_all *all, double old_x, double old_y, int sign)
{
	int	actual_map_x;
	int	actual_map_y;
	int	index;
	(void) old_y;

	(void) sign;
	actual_map_x = (int)(all->pos.p_x);
	actual_map_y = (int)(all->pos.p_y);
	index = actual_map_y * all->map.x + actual_map_x;
	if (all->map.line[index] == '1')
		all->pos.p_x = old_x;
	if (all->map.line[index] == '1')
		all->pos.p_y = old_y;
}

void	check_collision(t_all *all, double old_x, double old_y, int sign)
{
	int	next_map_x;
	int	next_map_y;
	int	index;
	(void) old_y;
	(void) old_x;

	(void) sign;
	next_map_x = (int)(all->pos.p_x + all->ray.orient_x * MOVE_SPEED);
	next_map_y = (int)(all->pos.p_y + all->ray.orient_y * MOVE_SPEED);
	index = next_map_y * all->map.x + next_map_x;
	if (all->ray.side == 0 && all->ray.r_dir_x > 0 && all->map.line[index] == '1')
		{
		all->pos.p_y = all->pos.p_y + all->ray.delta_dist_y * MOVE_SPEED /8;
		}
	if (all->ray.side == 0 && all->ray.r_dir_x < 0 && all->map.line[index] == '1')
		{
		all->pos.p_y = all->pos.p_y + all->ray.delta_dist_y * MOVE_SPEED /8;
		}
	if (all->ray.side == 1 && all->ray.r_dir_y < 0 && all->map.line[index] == '1')
		{
		all->pos.p_x = all->pos.p_x + all->ray.orient_x * MOVE_SPEED/8;
		}
	if (all->ray.side == 1 && all->ray.r_dir_y > 0 && all->map.line[index] == '1')
		{
		all->pos.p_x = all->pos.p_x + all->ray.orient_x * MOVE_SPEED/8;
		}
}

// move = ne change pas  ma carte, met a jour les pixels
//cast de ma position => donne la case 
//deplacement x= x+move_speed => on multiplie par le vecteur dorientation 
//pour tenir compte des changement de rotattion
void	move(double new_pos_x, double new_pos_y, t_all *all, int sign)
{
	int		next_index;
	int		map_x;
	int		map_y;
	// double	old_x;
	// double	old_y;

	(void) sign;

	// old_x = all->pos.p_x;
	// old_y = all->pos.p_y;
	map_x = (int)(new_pos_x);// + all->ray.orient_x * MOVE_SPEED);
	map_y = (int)(new_pos_y);// - all->ray.orient_y * MOVE_SPEED);
	next_index = map_y * all->map.x + map_x;
	if (all->map.line[next_index] != '1')
		all->pos.p_x = new_pos_x;
	if (all->map.line[next_index] != '1')
		all->pos.p_y = new_pos_y;
	// check_collision(all, old_x, old_y, sign);
	// check_collision2(all, old_x, old_y, sign);

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
