/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/11/18 13:31:58 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	esc_hook(int keysym, t_window *win)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(win->pt_mlx, win->pt_win);
		mlx_destroy_display(win->pt_mlx);
		free(win->pt_mlx);
		free(win->pt_win);
		exit (0);
	}
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
