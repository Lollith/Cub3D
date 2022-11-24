/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:02 by agouet            #+#    #+#             */
/*   Updated: 2022/11/24 08:27:05 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//idee
// si N , touche up  : vers le haut
//si E , fleche droite : vers la droite

// move = ne change pas  ma carte, met a jour les pixels
void	move(double new_position, t_all *all)
{
	all->pos.old_p_y = all->pos.p_y + MINI_P;//+ miniP sinon se decale avec la new pos definie ds keypress
	all->pos.old_p_x = all->pos.p_x + MINI_P;
	all->pos.p_y = new_position;
}
