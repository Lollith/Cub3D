/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/11 15:04:17 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_mouse(int x, int y, t_all *all)
{
	(void) y;
	if (x - all->win.mouse_position < 0)
		rotate(all, -1, MOUSE_SPEED);
	else
		rotate(all, 1, MOUSE_SPEED);
	all->win.mouse_position = x;
	return (0);
}

void	ft_key_loop_hook(t_all *all)
{
	mlx_hook(all->win.pt_win, MOUSEMOVE, PointerMotionMask, move_mouse, all);
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress_wsad, all);
	mlx_key_hook(all->win.pt_win, esc_hook, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
}
