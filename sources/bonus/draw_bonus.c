/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/12/16 15:36:39 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// creer une minimap , map.x = longueur de la map sur x
void	put_minimap(t_img *img, t_all *all)
{
	int	i;

	all->map.mini_pos = W_HEIGHT - all->map.y * MINI_CUB;
	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == '1')
			draw_mini_wall(&i, img, all, GREY);
		if (all->map.line[i] != ' ' && all->map.line[i] != '\n'
			&& all->map.line[i] != '1')
			draw_mini_wall(&i, img, all, TBLACK);
		i++;
	}
}

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
	if (all->map.x * MINI_CUB < W_WIDTH && all->map.y * MINI_CUB < W_HEIGHT)
	{
		put_minimap(&all->img_px, all);
		draw_heroe(&all->img_px, all);
	}
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
		all->img_px.mlx_img, 0, 0);
	mlx_destroy_image(all->win.pt_mlx, all->img_px.mlx_img);
	return (0);
}
