/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:50:33 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/05 13:23:50 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all(t_all *all)
{
	int	i;

	i = 0;
	if (all != NULL)
	{
		while (i < 4)
		{
			if (all->tex[i].dir != NULL)
				free(all->tex[i].dir);
			i++;
		}
		if (all->tex != NULL)
			free(all->tex);
		if (all->map.line != NULL)
			free(all->map.line);
	}
	return (0);
}

int	the_end(t_all *all)
{
	ft_distroy_img(all);
	mlx_destroy_window(all->win.pt_mlx, all->win.pt_win);
	mlx_destroy_display(all->win.pt_mlx);
	if (all->win.pt_mlx != NULL)
	{
		free(all->win.pt_mlx);
		all->win.pt_mlx = NULL;
	}
	return (-1);
}
