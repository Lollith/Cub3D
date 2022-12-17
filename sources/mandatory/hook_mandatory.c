/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/17 10:17:33 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//mlx put image = affiche limage
//destroy :// permet de mettre a jour mon image, pas de superposition des pixels
int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	update_move(all);
	update_rotation(all);
	esc_hook(all);
	img_creation(all);
	put_background(&all->img_px, all);
	raycasting(all);
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
		all->img_px.mlx_img, 0, 0);
	mlx_destroy_image(all->win.pt_mlx, all->img_px.mlx_img);
	return (0);
}

void	loop(t_all *all)
{
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress, all);
	mlx_hook(all->win.pt_win, KEYRELEASE, 1L << 1, keyrelease, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
	mlx_loop_hook(all->win.pt_mlx, &render, all);
	mlx_loop(all->win.pt_mlx);
}
