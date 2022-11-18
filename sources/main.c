/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/18 18:30:49 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//test


int	main(int ac, char **av)
{
	t_all	all;
	// t_map	map; // to be deleted later?

	if (check_args(ac, av) != 0) // to be upgraded: only ac == 2 checked
		return (1);
	
	//----------------a mettre ds le fichier initialisation----------------------
	all.map.line = NULL;
	
	all.img.addr = NULL;
	all.img.bpp = 0;
	all.img.endian = 0;
	all.img.line_len = 0;
	all.img.mlx_img = NULL;
	
	


	
	//--------------------------------initialisation----------------------------
	init_square_map(av, &all.map);//to be deleted later?
	create_window(&all.win);
	ft_key_loop_hook(&all.win);

	//--------------------------------fonctions---------------------------------
	// img_mlx  point rouge
	all.img.mlx_img = mlx_new_image(all.win.pt_mlx, W_WIDTH, W_HEIGHT);
	all.img.addr = mlx_get_data_addr(all.img.mlx_img, &all.img.bpp, 
		&all.img.line_len, &all.img.endian);
	
	
	//  render
	mlx_loop_hook(all.win.pt_mlx, &render, &all); //affiche pixel rouge


//tuto raycasting	
	// double posX = 200;
	// double posY = 200;
	// double dirX = -1;
	// double dirY = 0;
	// double planeX = 0;
	// double planeY = 0.66;
	// // double time = 0;
	// // double oldtime = 0;
	// int x = 0;
	// int lenght_plane =10; // w ds tuto valeur???
	// double ratioX; // cameraX
	// double raydirX;
	// double raydirY;
	// while (x < lenght_plane)
	// {
	// 	ratioX = 2 * x / (lenght_plane) - 1;
	// 	raydirX = dirX + planeX * ratioX;
	// 	raydirY = dirY + planeY * ratioX;
	// 	x++;
	// }


	//-------------------------------ends---------------------------------------
	mlx_loop(all.win.pt_mlx);
	// mlx_destroy_window(all.win.pt_mlx, all.win.pt_win);
	// mlx_destroy_display(all.win.pt_mlx);
	// free(all.win.pt_mlx);
	// free(all.win.pt_win);

	return (0);
}
