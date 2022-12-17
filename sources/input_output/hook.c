/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/17 10:31:37 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
