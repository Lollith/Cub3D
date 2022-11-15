/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:57 by agouet            #+#    #+#             */
/*   Updated: 2022/11/15 16:04:38 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysym.h>

# define W_WIDTH 800
# define W_HEIGHT 800

typedef struct s_window{
	void	*pt_mlx;
	void	*pt_win;
}t_window;

/*----------------------------------WINDOW------------------------------------*/
int		create_window(t_window *win);
void	ft_key_loop_hook(t_window *win);

/*----------------------------------------------------------------------------*/

#endif