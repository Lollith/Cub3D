/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:50:17 by lollith           #+#    #+#             */
/*   Updated: 2022/12/14 14:55:21 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(double new_pos_x, double new_pos_y, t_all *all)
{
	int		next_index;
	int		map_x;
	int		map_y;

	map_x = (int)(new_pos_x);
	map_y = (int)(new_pos_y);
	next_index = map_y * all->map.x + map_x;
	if (all->map.line[next_index] != '1')
		all->pos.p_x = new_pos_x;
	if (all->map.line[next_index] != '1')
		all->pos.p_y = new_pos_y;
}
