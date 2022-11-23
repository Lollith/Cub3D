/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/11/23 19:51:10 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// position initiale de perso
//all->map.x + 1 = size de ma ligne  avec \n
void	read_pos_ini(t_all *all)
{	
	int	i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == 'P')
		{
			all->pos.p_x = i % (all->map.x + 1);
			all->pos.p_y = i / (all->map.x + 1);
			all->pos.index = i;
		}
		i++;
	}
}

// creer une minimap , map.x = longueur de la map sur x
void	put_minimap(t_img *img, t_all *all)
{
	int	i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == '1')
			draw_wall(&i, img, all, 0x9E9E9E);
		//  if (all->map.line[i] != '1' && all->map.line[i] != '\n')
			// draw_wall(&i, img, all, 0x000000); // rempli entierement ma minimap , meme la ou P
		i++;
	}
}

int	render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	draw_heroe(&all->img_minimap, all);
	clean_px(&all->img_minimap, all);
	put_minimap(&all->img_minimap, all); // creer une minimap
	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
							all->img_minimap.mlx_img, 0, 0); // affiche l image
	return (0);
}
