/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:37 by agouet            #+#    #+#             */
/*   Updated: 2022/12/08 09:31:41 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_window(t_window *win)
{
	int	size_x;
	int	size_y;

	size_x = W_WIDTH;
	size_y = W_HEIGHT;
	win->pt_mlx = mlx_init();
	if (win->pt_mlx == NULL)
	{
		free(win->pt_mlx);
		//MESSAGE ERROR
		return (1);
	}
	win->pt_win = mlx_new_window(win->pt_mlx, size_x, size_y, "cub3D");
	// win->pt_mlx = NULL; //=> leak
	if (win->pt_win == NULL)
	{
		// mlx_destroy_window(win->pt_mlx, win->pt_win);
		// mlx_destroy_display(win->pt_mlx);
		// free(win->pt_win);
		// free(win->pt_mlx);
		// 
		//MESSAGE ERROR
		return (1);
	}
	return (0);
}
