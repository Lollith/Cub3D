/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:03:20 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/16 15:14:46 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//player position at start
void	read_pos_ini(t_all *all)
{	
	int	i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == 'N' || all->map.line[i] == 'S'
			|| all->map.line[i] == 'E' || all->map.line[i] == 'W')
		{
			all->pos.p_x = i % (all->map.x) + 0.5;
			all->pos.p_y = i / (all->map.x) + 0.5;
			all->pos.index = i;
		}
		i++;
	}
}

void	orientation_p(t_all *all)
{
	if (all->pos.p == 'N')
	{
		all->ray.orient_y = -1;
		all->ray.plane_x = 0.60;
	}
	if (all->pos.p == 'S')
	{
		all->ray.orient_y = 1;
		all->ray.plane_x = 0.60;
		all->pos.left_handed = 1;
	}
	if (all->pos.p == 'E')
	{
		all->ray.orient_x = 1;
		all->ray.plane_y = 0.60;
	}
	if (all->pos.p == 'W')
	{
		all->ray.orient_x = -1;
		all->ray.plane_y = 0.60;
		all->pos.left_handed = 1;
	}
}

void	loop(t_all *all)
{
	// ft_key_loop_hook(all);
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress, all);
	mlx_hook(all->win.pt_win, KEYRELEASE, 1L << 1, keyrelease, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
	mlx_loop_hook(all->win.pt_mlx, &render, all);
	mlx_loop(all->win.pt_mlx);
}
