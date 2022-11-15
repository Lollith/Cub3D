/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:05:37 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 13:27:21 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_window(t_window *wdata)
{
	int	size_x;
	int	size_y;

	size_x = W_WIDTH;
	size_y = W_HEIGHT;
	wdata->pt_mlx = mlx_init();
	if (wdata->pt_mlx == NULL)
	{
		free(wdata->pt_mlx);
		return (1);
	}
	wdata->pt_win = mlx_new_window(wdata->pt_mlx, size_x, size_y, "cub3D");
	if (wdata->pt_win == NULL)
	{
		mlx_destroy_display(wdata->pt_mlx);
		mlx_destroy_window(wdata->pt_mlx, wdata->pt_win);
		free(wdata->pt_win);
		free(wdata->pt_mlx);
		return (1);
	}
	return (0);
}
