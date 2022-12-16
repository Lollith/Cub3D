/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/16 15:41:04 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mls_mouse_move permet de garder la souris a la bonne place, + 
//depacement mon mouvement de x *
int	move_mouse(int x, int y, t_all *all)
{
	int	sign;

	(void) y;
	sign = 1;
	if (all->pos.left_handed)
		sign = -1;
	if (all->win.mouse_position > x)
	{	
		rotate(all, sign * -1, x * MOUSE_SPEED / 500);
		mlx_mouse_move(all->win.pt_mlx, all->win.pt_win,
			W_WIDTH / 2, W_HEIGHT / 2);
	}
	else if (all->win.mouse_position < x)
	{
		rotate(all, sign * 1, x * MOUSE_SPEED / 500);
		mlx_mouse_move(all->win.pt_mlx, all->win.pt_win,
			W_WIDTH / 2, W_HEIGHT / 2);
	}
	return (0);
}

void	loop(t_all *all)
{
	mlx_mouse_move(all->win.pt_mlx, all->win.pt_win, W_WIDTH / 2, W_HEIGHT / 2);
	mlx_hook(all->win.pt_win, MOUSEMOVE, PointerMotionMask, move_mouse, all);
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress, all);
	mlx_hook(all->win.pt_win, KEYRELEASE, 1L << 1, keyrelease, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
	mlx_loop_hook(all->win.pt_mlx, &render, all);
	mlx_loop(all->win.pt_mlx);
}
// mouse_move fixe la souis au milieu au lancement de la fenetre