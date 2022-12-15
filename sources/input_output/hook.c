/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/14 14:49:10 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ATTENTION ESC a refaire comletement  LEAKS
int	esc_hook(int keysym, t_all *all)
{
	if (keysym == XK_Escape)
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
int	keypress_wsad(int keysym, t_all *all)
{
	int	sign;

	sign = 1;
	if (all->pos.left_handed)
		sign = -1;
	if (keysym == XK_w || keysym == XK_Up)
		move(all->pos.p_x + all->ray.orient_x * MOVE_SPEED,
			all->pos.p_y + all->ray.orient_y * MOVE_SPEED, all);
	if (keysym == XK_s || keysym == XK_Down)
	{
		if (all->pos.left_handed)
			move(all->pos.p_x - all->ray.orient_x * MOVE_SPEED,
				all->pos.p_y - all->ray.orient_y * MOVE_SPEED, all);
		else
			move(all->pos.p_x - all->ray.orient_x * MOVE_SPEED,
				all->pos.p_y - all->ray.orient_y * MOVE_SPEED, all);
	}
	if (keysym == XK_a)
		move(all->pos.p_x + sign * all->ray.orient_y * MOVE_SPEED,
			all->pos.p_y - sign * all->ray.orient_x * MOVE_SPEED, all);
	if (keysym == XK_d)
		move(all->pos.p_x - sign * all->ray.orient_y * MOVE_SPEED,
			all->pos.p_y + sign * all->ray.orient_x * MOVE_SPEED, all);
	keypress_rotation(keysym, all);
	return (0);
}

int	keypress_rotation(int keysym, t_all *all)
{
	int	sign;

	sign = 1;
	if (all->pos.left_handed)
		sign = -1;
	if (keysym == XK_Right)
		rotate(all, sign, MOVE_SPEED);
	if (keysym == XK_Left)
		rotate(all, -sign, MOVE_SPEED);
	return (0);
}
