/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/16 09:58:18 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_window	data;//to be updated to win
	// t_all		all;
	t_map			map; // to be deleted later?
	
	if (check_args(ac, av) != 0) // to be upgraded: only ac == 2 checked
		return (1);
	init_square_map(av, &map);//to be deleted later?
	//init_all //inside the all init window etc//
	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
	// init_all(av, &all);
	// all.window = data; //to be deleted because this stage has to be done in all init

//tuto raycasting	
	// double posX = 200;
	// double posY = 200;
	double dirX = -1;
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.66;
	// double time = 0;
	// double oldtime = 0;
	int x = 0;
	int lenght_plane =10; // w ds tuto valeur???
	double ratioX; // cameraX
	double raydirX;
	double raydirY;
	while (x < lenght_plane)
	{
		ratioX = 2 * x / (lenght_plane) - 1;
		raydirX = dirX + planeX * ratioX;
		raydirY = dirY + planeY * ratioX;
		x++;
	}

	create_window(&data);
	ft_key_loop_hook(&data);
	mlx_loop(data.pt_mlx);
	mlx_destroy_window(data.pt_mlx, data.pt_win);
	mlx_destroy_display(data.pt_mlx);
	free(data.pt_mlx);
	return (0);
}
