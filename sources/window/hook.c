/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 09:42:48 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	esc_hook(int keysym, t_window *wdata)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(wdata->pt_mlx, wdata->pt_win);
	return (0);
}

int	ft_close(t_window *wdata)
{
	mlx_loop_end(wdata->pt_mlx);
	return (0);
}

void	ft_key_loop_hook(t_window *wdata)
{
	mlx_key_hook(wdata->pt_win, esc_hook, wdata->pt_mlx);
	mlx_hook(wdata->pt_win, 17, 0, ft_close, wdata);
}
