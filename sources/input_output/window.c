/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:37 by agouet            #+#    #+#             */
/*   Updated: 2022/12/11 10:08:06 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_window(t_all *all, t_window *win)
{
	int	size_x;
	int	size_y;

	size_x = W_WIDTH;
	size_y = W_HEIGHT;
	win->pt_mlx = mlx_init();
	if (win->pt_mlx == NULL)
	{
		free(win->pt_mlx);
		return (msg_err("mlx_init", NULL, 2));
	}
	win->pt_win = mlx_new_window(win->pt_mlx, size_x, size_y, "cub3D");
	if (win->pt_win == NULL)
	{
		mlx_destroy_display(win->pt_mlx);
		free(win->pt_mlx);
		free_all(all);
		return (msg_err("Can't create window", NULL, 2));
	}
	return (0);
}
