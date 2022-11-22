/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:23:02 by agouet            #+#    #+#             */
/*   Updated: 2022/11/22 14:11:42 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//idee
// si N , touche up  : vers le haut
//si E , fleche droite : vers la droite


// move = change ma carte
void move(double new_position, t_img *img,t_all *all)
{
	(void) img;
	all->pos.old_p_y = all->pos.p_y + 0.1;  //+0,1 sinon se decale avec la new pos definie ds keypress
	all->pos.old_p_x = all->pos.p_x + 0.1; 
	all->pos.p_y = new_position;
}