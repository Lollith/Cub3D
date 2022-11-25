/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/25 14:12:11 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_all all;

	if (check_args(ac, av) != 0)
		return (1);
	if (ft_init(av[1]) == 1)
		return (1);
	//--------------------------------initialisation----------------------------
	init_square_map(av, &all.map); // to be deleted later?
	if(create_window(&all.win) == 1) // a essayer sur WSL segfault?
		return 0;

	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
	// init_all(av, &all);
	// all.window = data; //to be deleted because this stage has to be done in all init

	//--------------------------------fonctions---------------------------------
	// creation img minimap
	img_creation(&all);
	read_pos_ini(&all);
	// commandes
	ft_key_loop_hook(&all);
	//  render
	mlx_loop_hook(all.win.pt_mlx, &render, &all); // boucle sur mes images

	
	//-----------------ends---------------------------------------
	mlx_loop(all.win.pt_mlx);
	the_end(&all);
	//---------------------------above to be deleted later----------------------------
	return (0);
}
