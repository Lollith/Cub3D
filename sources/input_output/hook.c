/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/16 15:44:12 by agouet           ###   ########.fr       */
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


int	update_rotation(t_all *all)
{
	int	sign;

	sign = 1;
	if (all->pos.left_handed)
		sign = -1;
	if (all->key.rot_right)
		rotate(all, sign, MOVE_SPEED);
	if (all->key.rot_left)
		rotate(all, -sign, MOVE_SPEED);
	return (0);
}

int	esc_hook(t_all *all)
{
	if (all->key.esc == 1)
	{
		the_end(all);
		free_all(all);
		exit(1);
	}
	return (0);
}

int	ft_close(t_window *win)
{
	mlx_loop_end(win->pt_mlx);
	return (0);
}

int	keypress(int keysym, t_all *all)
{
	if (keysym == XK_w || keysym == XK_Up)
		all->key.up = 1;
	if (keysym == XK_s || keysym == XK_Down)
		all->key.down = 1;
	if (keysym == XK_a)
		all->key.left = 1;
	if (keysym == XK_d)
		all->key.right = 1;
	if (keysym == XK_Right)
		all->key.rot_right = 1;
	if (keysym == XK_Left)
		all->key.rot_left = 1;
	if (keysym == XK_Escape)
		all->key.esc = 1;
	return (0);
}

int	keyrelease(int keysym, t_all *all)
{
	if (keysym == XK_w || keysym == XK_Up)
		all->key.up = 0;
	if (keysym == XK_s || keysym == XK_Down)
		all->key.down = 0;
	if (keysym == XK_a)
		all->key.left = 0;
	if (keysym == XK_d)
		all->key.right = 0;
	if (keysym == XK_Right)
		all->key.rot_right = 0;
	if (keysym == XK_Left)
		all->key.rot_left = 0;
	if (keysym == XK_Escape)
		all->key.esc = 0;
	return (0);
}

