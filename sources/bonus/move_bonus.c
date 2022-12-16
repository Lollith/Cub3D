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
// // faire pour x et y => plus precis

// move = ne change pas  ma carte, met a jour les pixels
//cast de ma position => donne la case 
//deplacement x= x+move_speed => on multiplie par le vecteur dorientation 
//pour tenir compte des changement de rotattion
void	move(double new_pos_x, double new_pos_y, t_all *all)
{
	double	old_x;
	double	old_y;
	int		map_x;
	int		map_y;
	// int		next_index;
	int		newmap_x;
	int		newmap_y;

	newmap_x = (int)(new_pos_x);
	newmap_y = (int)(new_pos_y);
	map_x = (int)(all->pos.p_x);
	map_y = (int)(all->pos.p_y);
	
	old_x = all->pos.p_x;
	old_y = all->pos.p_y;
	// next_index = ft_next_index(new_pos_x, new_pos_y, all);
	if (all->map.line[map_y * all->map.x +newmap_x] == '0')
		all->pos.p_x = new_pos_x;

	if (all->map.line[newmap_y * all->map.x +map_x] == '0')
		all->pos.p_y = new_pos_y;
	
}
//verifier 1 axe puis lautre