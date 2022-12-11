/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/11 13:21:10 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ATTENTION ESC a refaire comletement  LEAKS
int	esc_hook(int keysym, t_all *all)
{
	(void) all;
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

void	mouse_rotate(t_all *all, int sign, int *x, double speed)
{
	double	old_orient_x;
	double	old_plane_x;

	old_orient_x = all->ray.orient_x;
	old_plane_x = all->ray.plane_x;
	all->ray.orient_x = all->ray.orient_x * cos(sign * speed)
		- all->ray.orient_y * sin(sign * speed);
	all->ray.plane_x = all->ray.plane_x * cos(sign * speed)
		- all->ray.plane_y * sin (sign * speed);
	all->ray.orient_y = old_orient_x * sin( sign * speed)
		+ all->ray.orient_y * cos(sign * speed);
	all->ray.plane_y = old_plane_x * sin( sign * speed)
		+ all->ray.plane_y * cos (sign * speed);
}

int	move_mouse(int x, int y, t_all *all)
{
double speed= MOUSE_SPEED;
	if ( x < W_WIDTH -20 || x > 20)
		speed =  MOUSE_SPEED *10;
		

		
	if (x - all->mouse_position < 0)
		mouse_rotate(all, -1, &x, speed);
	else
		mouse_rotate(all, 1, &x, speed);
	all->mouse_position = x;
	return 0;

}

void	ft_key_loop_hook(t_all *all)
{
	// mlx_hook(all->win.pt_win, MOUSEMOVE, 0, move_mouse, all);
	// mlx_hook(all->win.pt_win, MOUSEMOVE, PointerMotionMask, init_mouse, all);
	mlx_hook(all->win.pt_win, MOUSEMOVE, PointerMotionMask, move_mouse, all);
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress_wsad, all);
	mlx_key_hook(all->win.pt_win, esc_hook, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
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
			all->pos.p_y + all->ray.orient_y * MOVE_SPEED, all, 0);
	if (keysym == XK_s || keysym == XK_Down)
	{
		if (all->pos.left_handed)
			move(all->pos.p_x - all->ray.orient_x * MOVE_SPEED + 0.02,
				all->pos.p_y - all->ray.orient_y * MOVE_SPEED, all, sign);
		else
			move(all->pos.p_x - all->ray.orient_x * MOVE_SPEED,
				all->pos.p_y - all->ray.orient_y * MOVE_SPEED, all, -1);
	}
	if (keysym == XK_a)
		move(all->pos.p_x + sign * all->ray.orient_y * MOVE_SPEED,
			all->pos.p_y - sign * all->ray.orient_x * MOVE_SPEED, all, 0);
	if (keysym == XK_d)
		move(all->pos.p_x - sign * all->ray.orient_y * MOVE_SPEED,
			all->pos.p_y + sign * all->ray.orient_x * MOVE_SPEED, all, 0);
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
		rotate(all, sign);
	if (keysym == XK_Left)
		rotate(all, -sign);
	return (0);
}
