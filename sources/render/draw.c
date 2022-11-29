/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/11/29 13:02:32 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// position initiale de perso
//all->map.x + 1 = size de ma ligne  avec \n
void	read_pos_ini(t_all *all)
{	
	int	i;
	//map.x ne plus mettre +1
	i = 0;

	while (all->map.line[i])
	{
		if (all->map.line[i] == 'P')
		{
			all->pos.p_x = i % (all->map.x);
			all->pos.p_y = i / (all->map.x);
			all->pos.index = i;
		}
		i++;
	}
}

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
		 if (all->map.line[i] != '1' && all->map.line[i] != '\n')
			draw_wall(&i, img, all, BLACK); // rempli entierement ma minimap , meme la ou P
		i++;
	}
}

int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	raycasting(all);
	put_minimap(&all->img_minimap, all); // creer une minimap
	draw_heroe(&all->img_minimap, all);
	clean_px(&all->img_minimap, all);
	draw_ray(&all->img_minimap, all);
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
							all->img_minimap.mlx_img, 0, 0); // affiche l image
	return (0);
}
