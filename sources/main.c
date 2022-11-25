/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/25 17:51:21 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	// t_all	all;
	
	if (check_args(ac, av) != 0)
		return (1);
	if (ft_init(av[1]) == 1)
		return (1);
// //--------------------------------initialisation----------------------------
// 	init_square_map(av, &all.map);//to be deleted later?
// 	create_window(&all.win);
	
// 	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
// 	// init_all(av, &all);
// 	// all.window = data; //to be deleted because this stage has to be done in all init

// //--------------------------------fonctions---------------------------------
// 	// commandes
// 	ft_key_loop_hook(&all.win);
// 	// creation img minimap
// 	all.img_minimap.mlx_img = mlx_new_image(all.win.pt_mlx, W_WIDTH, W_HEIGHT);
// 	all.img_minimap.addr = mlx_get_data_addr(all.img_minimap.mlx_img, 
// 		&all.img_minimap.bpp, &all.img_minimap.line_len, &all.img_minimap.endian);

// 	//  render
// 	mlx_loop_hook(all.win.pt_mlx, &render, &all); //boucle sur mes images
 
//  //-------------------------------ends---------------------------------------
// 	mlx_loop(all.win.pt_mlx);
// 	the_end(&all);
	//---------------------------above to be deleted later----------------------------
	return (0);
}
