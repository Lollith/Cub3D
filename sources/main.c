/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/18 16:43:34 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (check_args(ac, av) != 0)
		return (1);
	if (ft_init(av[1]) == 1)
		return (1);
	//---------------------------below to be deleted later----------------------------
	// t_window	win;
	// t_map		map;
	// //--------------------------------initialisation----------------------------
	// init_square_map(av, &map);//to be deleted later?
	// // get map will be all.map.map = get_map(av) struct map to be deleted in main after that
	// // init_all(av, &all);
	// // all.window = data; //to be deleted because this stage has to be done in all init
	// create_window(&win);
	// //-------------------------fonctions----------------------------------------
	// ft_key_loop_hook(&win);

	// //--------------------------------end---------------------------------------
	// mlx_loop(win.pt_mlx);
	// mlx_destroy_window(win.pt_mlx, win.pt_win);
	// mlx_destroy_display(win.pt_mlx);
	// free(win.pt_mlx);
	//---------------------------above to be deleted later----------------------------
	return (0);
}
