/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:15:43 by lollith           #+#    #+#             */
/*   Updated: 2022/11/22 17:07:29 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// position initiale de perso
//all->map.x + 1 = size de ma ligne  avec \n
void read_pos_ini(t_all *all)
{	
	int i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == 'P')
		{
			all->pos.p_x = i % (all->map.x + 1) ;
			all->pos.p_y = i / (all->map.x + 1) ;
			all->pos.position_i = i;
		}
		i++;
	}
	// printf("%d\n", all->pos.position_i);
}

// point de pixels rouge
void img_pix(t_img *img, int x, int y, int color)
{
	char *pixel;
	int i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void draw_wall(int *pt_i, t_img *img, t_all *all, int color)
{	
	int x;
	int y;
	int i;
	
	i = *pt_i;
	y = i / (all->map.x + 1) * MINI_SQUARE;
	while (y < (i / (all->map.x + 1) + 1) * MINI_SQUARE)
	{
		x = i % (all->map.x + 1) * MINI_SQUARE;
		while (x < (i % (all->map.x + 1) + 1) * MINI_SQUARE)
		{
			img_pix(img, x, y, color);
			x++;
		}
		y++;
	}
}

// creer une minimap , map.x = longueur de la map sur x
void put_minimap(t_img *img, t_all *all)
{
	int i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == '1')
			draw_wall(&i, img, all, 0x9E9E9E);
		 if (all->map.line[i] != '1' && all->map.line[i] != '\n')
			draw_wall(&i, img, all, 0x000000); // rempli entiewrement ma minimap , meme la ou P
		i++;
	}
}

// void draw_heroe2(int *pt_i, t_img *img, t_all *all)
// {
// 	int i;

// 	i = *pt_i;

// 	int y = (int)all->pos.p_y * MINI_SQUARE;
// 	while(y < (i / ((all->map.x + 1)) + 0.2) * MINI_SQUARE)
// 	{
// 		int x = (int)all->pos.p_x * MINI_SQUARE;
// 		while (x < ((i % (all->map.x + 1)  + 0.2) * MINI_SQUARE))
// 		{
// 			img_pix(img,  x , y, 0xFFFF00);
// 			x++;
// 		}
// 		y++;
// 	}
// }	

// void put_heroe(t_img *img, t_all *all)
// {
	// // // int i;

	// // // i = 0;
	// // // while (all->map.line[i])
	// // {
	// 	if (all->map.line[i] == 'P')
			// draw_heroe(&i, img, all);
		// i++;
	// }
// }

// size of heroe on minimap = 0.2
//pos.p_x et y se mette a jour a linitialisation puis en fct des mouvement
// la boucle de render permet de faire avancer le personnage
void draw_heroe( t_img *img, t_all *all)
{
	int y = all->pos.p_y * MINI_SQUARE;
	while((y <( all->pos.position_i / (all->map.x + 1) + 0.2) * MINI_SQUARE) )
	{
		int x = (int)all->pos.p_x * MINI_SQUARE;
		while (x < ((all->pos.position_i % (all->map.x + 1)  + 0.2) * MINI_SQUARE))
		{
			img_pix(img,  x , y, 0xFFFF00);
			x++;
		}
		y++;
	}
	if((int)all->pos.old_p_x != 0 && (int) all->pos.old_p_y != 0)
	{
		int z = all->pos.old_p_y * MINI_SQUARE;
		while((z <( all->pos.position_i / (all->map.x + 1) + 0.2) * MINI_SQUARE) )
		{
			int w = (int)all->pos.old_p_x * MINI_SQUARE;
			while (w < ((all->pos.position_i % (all->map.x + 1) + 0.2) * MINI_SQUARE))
			{
				img_pix(img, w , z , 0x000000);
				w++;
			}
			z++;
		}
	}
}	




int render(t_all *all)
{
	if (all->win.pt_win == NULL)
		return (1);
	put_minimap(&all->img_minimap, all); // creer une minimap
	// put_heroe(&all->img_minimap, all); //crer les pixels du hero , par dessus minimap
	draw_heroe(&all->img_minimap, all);


	mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
							all->img_minimap.mlx_img, 0, 0); // affiche l image
	// mlx_put_image_to_window(all->win.pt_mlx, all->win.pt_win,
							// all->heroe.mlx_img, 0, 0); // affiche l image
	return (0);
}