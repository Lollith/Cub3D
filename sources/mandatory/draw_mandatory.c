/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/12/11 14:38:10 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//mlx put image = affiche limage
//destroy :// permet de mettre a jour mon image, pas de superposition des pixels
int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	img_creation(all);
	put_background(&all->img_px, all);
	raycasting(all);
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
		all->img_px.mlx_img, 0, 0);
	mlx_destroy_image(all->win.pt_mlx, all->img_px.mlx_img);
	return (0);
}
