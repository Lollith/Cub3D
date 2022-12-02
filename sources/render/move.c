/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:02 by agouet            #+#    #+#             */
/*   Updated: 2022/12/02 08:45:58 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//idee
// si N , touche up  : vers le haut
//si E , fleche droite : vers la droite

// move = ne change pas  ma carte, met a jour les pixels
//cast de ma position => donne la case 
void	move(double new_pos_X, double new_pos_Y, double sign, t_all *all)
{
	int	next_index;
	int	map_x;
	int	map_y;

	map_x = (int)(new_pos_X + MINI_P/2 + sign * 0.2 );
	map_y = (int)(new_pos_Y + MINI_P/2 + sign * 0.2);
	next_index = map_y * all->map.x + map_x;
	if (all->map.line[next_index] != '1')
	{
		all->pos.old_p_y = all->pos.p_y + MINI_P;
		all->pos.old_p_x = all->pos.p_x + MINI_P;
		all->pos.p_x = new_pos_X;
		all->pos.p_y = new_pos_Y;
	}
}
