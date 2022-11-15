/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 18:07:34 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//test

// point de pixels rouge
int	render(t_window *win)
{
	int i = 0;
	int j;
	/* if window has been destroyed, we don't want to put the pixel ! */
	if (win->pt_win != NULL)
	{
		while (i <= 20)
		{
			j = 0;
			while (j <= 20)
			{
				mlx_pixel_put(win->pt_mlx, win->pt_win, 200+i , 200+j, 0xFF0000);
				j++;
			}
			i++;
		}
	}
	return (0);
}



int	main( void )
{
	t_window	win;
	
	// initialisation
	create_window(&win);
	
	ft_key_loop_hook(&win);

	// test
	mlx_loop_hook(win.pt_mlx, &render, &win); //affiche pixel rouge
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

	// end
	mlx_loop(win.pt_mlx);
	// mlx_destroy_window(wdata.pt_mlx, wdata.pt_win);
	mlx_destroy_display(win.pt_mlx);
	free(win.pt_mlx);
	return (0);
}
