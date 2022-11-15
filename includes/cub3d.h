/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:57 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 14:10:20 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>

# define W_WIDTH 1800
# define W_HEIGHT 1200

typedef struct s_window{
	void	*pt_mlx;
	void	*pt_win;
}t_window;

typedef struct s_map
{
	char	**map;
	int		map_x;
	int		map_y;
}t_map;

typedef struct s_texture
{
	int	*n;
	int	*s;
	int	*w;
	int	*e;
	int	c;
	int	f;
}t_texture;

typedef struct s_all
{
	t_mlx		window;
	t_map		map;
	t_texture	tex;
}t_all;


/*----------------------------------WINDOW------------------------------------*/
int		create_window(t_window *data);
void	ft_key_loop_hook(t_window *data);

/*----------------------------------------------------------------------------*/

/*-----------------------------------UTILS------------------------------------*/

/*----------------------------------------------------------------------------*/

#endif