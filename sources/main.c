/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 15:43:33 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_window	data;//to be updated to win
	// t_all		all;
	
	if (check_args(ac, av) != 0) // to be upgraded: only ac == 2 checked
		return (1);
	//init_all //inside the all init window etc//
	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
	// init_all(av, &all);
	// all.window = data; //to be deleted because this stage has to be done in all init
	create_window(&data);
	ft_key_loop_hook(&data);
	mlx_loop(data.pt_mlx);
	mlx_destroy_window(data.pt_mlx, data.pt_win);
	mlx_destroy_display(data.pt_mlx);
	free(data.pt_mlx);
	return (0);
}
