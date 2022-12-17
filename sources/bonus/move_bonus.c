/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:02 by agouet            #+#    #+#             */
/*   Updated: 2022/12/13 13:2 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//gestion collision =)
//verifier 1 axe puis lautre
// move = ne change pas  ma carte, met a jour les pixels
//cast de ma position => donne la case 
//deplacement x= x+move_speed => on multiplie par le vecteur dorientation 
//pour tenir compte des changement de rotattion
void	move(double new_pos_x, double new_pos_y, t_all *all)
{
	int		map_x;
	int		map_y;
	int		newmap_x;
	int		newmap_y;

	newmap_x = (int)(new_pos_x);
	newmap_y = (int)(new_pos_y);
	map_x = (int)(all->pos.p_x);
	map_y = (int)(all->pos.p_y);
	if (all->map.line[map_y * all->map.x + newmap_x] == '0')
		all->pos.p_x = new_pos_x;
	if (all->map.line[newmap_y * all->map.x + map_x] == '0')
		all->pos.p_y = new_pos_y;
}

// mls_mouse_move permet de garder la souris a la bonne place, + 
//depacement mon mouvement de x *
int	move_mouse(int x, int y, t_all *all)
{
	int	sign;

	(void) y;
	sign = 1;
	if (all->pos.left_handed)
		sign = -1;
	if (all->win.mouse_position > x)
	{	
		rotate(all, sign * -1, x * MOUSE_SPEED / 500);
		mlx_mouse_move(all->win.pt_mlx, all->win.pt_win,
			W_WIDTH / 2, W_HEIGHT / 2);
	}
	else if (all->win.mouse_position < x)
	{
		rotate(all, sign * 1, x * MOUSE_SPEED / 500);
		mlx_mouse_move(all->win.pt_mlx, all->win.pt_win,
			W_WIDTH / 2, W_HEIGHT / 2);
	}
	return (0);
}
