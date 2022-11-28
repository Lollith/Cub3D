/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:50:33 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/28 17:12:03 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all(t_all *all)
{
	if (all != NULL)
	{
		if (all->tex.n != NULL)
			free(all->tex.n);
		if (all->tex.s != NULL)
			free(all->tex.s);
		if (all->tex.w != NULL)
			free(all->tex.w);
		if (all->tex.e != NULL)
			free(all->tex.e);
		if (all->map.line != NULL)
			free(all->map.line);
	}
	return (0);
}

int	the_end(t_all *all)
{
	mlx_destroy_window(all->win.pt_mlx, all->win.pt_win);
	mlx_destroy_image(all->win.pt_mlx, all->img_minimap.mlx_img);
	mlx_destroy_display(all->win.pt_mlx);
	// free(all->map.line);
	free(all->win.pt_mlx);
	return (-1);
}
