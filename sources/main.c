/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/17 16:38:31 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{

	if (check_args(ac, av) != 0)
		return (1);
	ft_init(av[1]);
	//---------------------------below to be deleted later----------------------------
	t_window	win;
	t_map		map;
	t_all	all;
	
	//----------------a mettre ds le fichier initialisation----------------------
	all.img_minimap.addr = NULL;
	all.img_minimap.bpp = 0;
	all.img_minimap.endian = 0;
	all.img_minimap.line_len = 0;
	all.img_minimap.mlx_img = NULL;
	
	all.map.line = NULL;
	

	//--------------------------------initialisation----------------------------
	init_square_map(av, &all.map);//to be deleted later?
	create_window(&all.win);
	
	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
	// init_all(av, &all);
	// all.window = data; //to be deleted because this stage has to be done in all init

	//-------------------------fonctions----------------------------------------
	ft_key_loop_hook(&win);

	
	//--------------------------------fonctions---------------------------------
	// creation img minimap
	all.img_minimap.mlx_img = mlx_new_image(all.win.pt_mlx, W_WIDTH, W_HEIGHT);
	all.img_minimap.addr = mlx_get_data_addr(all.img_minimap.mlx_img, 
		&all.img_minimap.bpp, &all.img_minimap.line_len, &all.img_minimap.endian);

	//  render
	mlx_loop_hook(all.win.pt_mlx, &render, &all); //boucle sur mes images


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
	the_end(&all);

	return (0);
}
