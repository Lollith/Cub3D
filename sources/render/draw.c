/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/12/01 17:35:56 by lollith          ###   ########.fr       */
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
			draw_wall(&i, img, all, GREY);
		// rempli entierement ma minimap , meme la ou P
		if (all->map.line[i] != '1' && all->map.line[i] != '\n')
			draw_wall(&i, img, all, BLACK);
		i++;
	}
}

//mlx put image = affiche limage
//destroy :// permet de mettre a jour mon image, pas de superposition des pixels
int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	img_creation(all);
	raycasting(all);
	put_minimap(&all->img_minimap, all);
	draw_heroe(&all->img_minimap, all);
	// draw_ray(&all->img_minimap, all);
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
		all->img_minimap.mlx_img, 0, 0);
	mlx_destroy_image(all->win.pt_mlx, all->img_minimap.mlx_img);
	return (0);
}
