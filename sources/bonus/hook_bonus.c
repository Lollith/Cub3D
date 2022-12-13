/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/13 10:34:51 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// mls_mouse_move permet de garder la souris a la bonne place, + depacement mon mouvement de x *
int	move_mouse(int x, int y, t_all *all)
{
	(void) y;
	(void) x;
	if (all->win.mouse_position > x)
	{	
		rotate(all, -1, x * MOUSE_SPEED / 500);
		mlx_mouse_move(all->win.pt_mlx, all->win.pt_win, W_WIDTH/2, W_HEIGHT/2);
	}
	else if (all->win.mouse_position < x)
	{
		rotate(all, 1, x * MOUSE_SPEED / 500);
		mlx_mouse_move(all->win.pt_mlx, all->win.pt_win, W_WIDTH/2, W_HEIGHT/2);
	}
	return (0);
}

void	ft_key_loop_hook(t_all *all)
{
	mlx_mouse_move(all->win.pt_mlx, all->win.pt_win, W_WIDTH/2, W_HEIGHT/2);
	mlx_hook(all->win.pt_win, MOUSEMOVE, PointerMotionMask, move_mouse, all);
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress_wsad, all);
	mlx_key_hook(all->win.pt_win, esc_hook, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
}
