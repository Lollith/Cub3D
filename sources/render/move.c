/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:02 by agouet            #+#    #+#             */
/*   Updated: 2022/11/29 15:02:38 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//idee
// si N , touche up  : vers le haut
//si E , fleche droite : vers la droite

// move = ne change pas  ma carte, met a jour les pixels
void	move(double new_pos_X, double new_pos_Y, double sign, t_all *all)
{
	
	int next_index = (int)(new_pos_Y + MINI_P+ sign * 0.2) * (all->map.x) + (int)(new_pos_X + MINI_P+(sign *0.2)); //cast pour etre ds une case 1 ou 0
	if (all->map.line[next_index] != '1') //cast pour etre ds une case 1 ou 0
	{
		all->pos.old_p_y = all->pos.p_y + MINI_P;//+ miniP sinon se decale avec la new pos definie ds keypress
		all->pos.old_p_x = all->pos.p_x + MINI_P;
		all->pos.p_x = new_pos_X;
		all->pos.p_y = new_pos_Y;
	}
}
