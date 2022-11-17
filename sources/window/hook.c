/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/11/17 19:13:24 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	esc_hook(int keysym, t_window *win)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(win->pt_mlx, win->pt_win);
	return (0);
}

int	ft_close(t_window *win)
{
	mlx_loop_end(win->pt_mlx);
	return (0);
}

void	ft_key_loop_hook(t_window *win)
{
	mlx_key_hook(win->pt_win, esc_hook, win->pt_mlx);
	mlx_hook(win->pt_win, 17, 0, ft_close, win);
}
