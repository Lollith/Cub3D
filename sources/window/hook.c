/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/11/22 17:21:39 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ATTENTION ESC a refaire comletement  LEAKS
int	esc_hook(int keysym, t_window *win)
{
	if (keysym == XK_Escape)
	{
		free(win->pt_mlx);
		exit (0);
	}
	return (0);
}

int	ft_close(t_window *win)
{
	mlx_loop_end(win->pt_mlx);
	return (0);
}

void	ft_key_loop_hook(t_all *all)
{
	mlx_hook(all->win.pt_win, 2, 1L << 0, keypress, all);
	mlx_key_hook(all->win.pt_win, esc_hook, all->win.pt_mlx);
	mlx_hook(all->win.pt_win, 17, 0, ft_close, &all->win);
}

int	keypress(int keysym, t_all *all)
{
	if (keysym == XK_w || keysym == XK_Up)
		move(all->pos.p_y - 0.1, all);
	// if (keysym == XK_s || keysym == XK_Down)
	// 	move_down(all);
	// if (keysym == XK_a || keysym == XK_Left)
	// 	move_left(all);
	// if (keysym == XK_d || keysym == XK_Right)
	// 	move_right(all);
	return (0);
}