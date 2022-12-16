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
int	check_collision(t_all *all, double old_x, double old_y)
{
	int	actual_map_x;
	int	actual_map_y;
	int	index;

	actual_map_x = (int)(all->pos.p_x);
	actual_map_y = (int)(all->pos.p_y);
	index = actual_map_y * all->map.x + actual_map_x;
	if (all->map.line[index] == '1')
		all->pos.p_x = old_x;
	if (all->map.line[index] == '1')
	{
		all->pos.p_y = old_y;
		return (1);
	}
	return (0);
}

int	ft_next_index(double new_pos_x, double new_pos_y, t_all *all)
{
	int		next_index;
	int		map_x;
	int		map_y;

	map_x = (int)(new_pos_x);
	map_y = (int)(new_pos_y);
	next_index = map_y * all->map.x + map_x;
	return (next_index);
}

// move = ne change pas  ma carte, met a jour les pixels
//cast de ma position => donne la case 
//deplacement x= x+move_speed => on multiplie par le vecteur dorientation 
//pour tenir compte des changement de rotattion
void	move(double new_pos_x, double new_pos_y, t_all *all)
{
	double	old_x;
	double	old_y;
	int		next_index;

	old_x = all->pos.p_x;
	old_y = all->pos.p_y;
	next_index = ft_next_index(new_pos_x, new_pos_y, all);
	if (all->map.line[next_index] != '1')
	{
		all->pos.p_x = new_pos_x;
		all->pos.p_y = new_pos_y;
	}
	else
	{
		all->pos.p_x = all->pos.p_x;
		all->pos.p_y = new_pos_y;
	}	
	if (check_collision(all, old_x, old_y))
	{
		all->pos.p_x = new_pos_x;
		all->pos.p_y = all->pos.p_y;
	}
	check_collision(all, old_x, old_y);
}
