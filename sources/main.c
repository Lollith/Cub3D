/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/28 16:31:06 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_all	all;

	if (check_args(ac, av) != 0)
		return (1);
	if (ft_init(av[1]) == 1)
		return (1);
// //--------------------------------initialisation----------------------------
	init_square_map(av, &all.map);//to be deleted later?
// 	create_window(&all.win);
	
// 	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
// 	// init_all(av, &all);
// 	// all.window = data; //to be deleted because this stage has to be done in all init

//--------------------------------fonctions---------------------------------
	// creation img minimap
	img_creation(&all);
	read_pos_ini(&all);
	// commandes
	ft_key_loop_hook(&all);
	//  render
	mlx_loop_hook(all.win.pt_mlx, &render, &all); //boucle sur mes images
 
//  //-------------------------------ends---------------------------------------
// 	mlx_loop(all.win.pt_mlx);
// 	the_end(&all);
	//---------------------------above to be deleted later----------------------------
	return (0);
}

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