/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:30:36 by lollith           #+#    #+#             */
/*   Updated: 2022/12/17 10:31:26 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

// deplacement droite et gauche:ex si  dir_y = -1 et dir_x= 0 (ini), 
//pour aller a droite et a gauche => mes dir doivent etre inversee dc pos_x 
//doit aller vers -1 au lieu de 0 
//rotate:  to rotate a vector  , * with the matrix rotation
//[ cos(a) -sin(a) ]
//[ sin(a)  cos(a) ]
int	update_move(t_all *all)
{
	int	sign;

	sign = 1;
	if (all->pos.left_handed)
		sign = -1;
	if (all->key.up == 1)
		move(all->pos.p_x + all->ray.orient_x * MOVE_SPEED,
			all->pos.p_y + all->ray.orient_y * MOVE_SPEED, all);
	if (all->key.down == 1)
	{
		if (all->pos.left_handed)
			move(all->pos.p_x - all->ray.orient_x * MOVE_SPEED,
				all->pos.p_y - all->ray.orient_y * MOVE_SPEED, all);
		else
			move(all->pos.p_x - all->ray.orient_x * MOVE_SPEED,
				all->pos.p_y - all->ray.orient_y * MOVE_SPEED, all);
	}
	if (all->key.left == 1)
		move(all->pos.p_x + sign * all->ray.orient_y * MOVE_SPEED,
			all->pos.p_y - sign * all->ray.orient_x * MOVE_SPEED, all);
	if (all->key.right == 1)
		move(all->pos.p_x - sign * all->ray.orient_y * MOVE_SPEED,
			all->pos.p_y + sign * all->ray.orient_x * MOVE_SPEED, all);
	return (0);
}
