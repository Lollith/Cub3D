/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 09:44:26 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main( void )
{
	t_window	data;

	create_window(&data);
	ft_key_loop_hook(&data);
	mlx_loop(data.pt_mlx);
	mlx_destroy_window(data.pt_mlx, data.pt_win);
	mlx_destroy_display(data.pt_mlx);
	free(data.pt_mlx);
	return (0);
}
