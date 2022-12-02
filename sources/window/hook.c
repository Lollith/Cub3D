/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/02 14:12:31 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ATTENTION ESC a refaire comletement  LEAKS
int	esc_hook(int keysym, t_all *all)
{
	(void) all;
	if (keysym == XK_Escape)
		exit(1);
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
	mlx_key_hook(all->win.pt_win, esc_hook, all);
	mlx_hook(all->win.pt_win, 17, 0, ft_close, &all->win);
}

// signe  pour decallage du perso sur minimap +1.1 pour decaller un peu plus, 
//correction manuelle
int	keypress(int keysym, t_all *all)
{
	if (keysym == XK_w || keysym == XK_Up)
		move(all->pos.p_x, all->pos.p_y - MINI_MOV, -1.1, all);
	if (keysym == XK_s || keysym == XK_Down)
		move(all->pos.p_x, all->pos.p_y + MINI_MOV, 1, all);
	if (keysym == XK_a || keysym == XK_Left)
		move(all->pos.p_x - MINI_MOV, all->pos.p_y, -1.1, all);
	if (keysym == XK_d || keysym == XK_Right)
		move(all->pos.p_x + MINI_MOV, all->pos.p_y, 1, all);
	return (0);
}
