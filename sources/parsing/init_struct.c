/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:12:46 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/09 17:17:17 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_pos(t_pos *pos)
{
	pos->p_x = 0.2;
	pos->p_y = 0.2;
	pos->p = 'P';
	pos->left_handed = 0;
}

int	init_tex(t_all *all)
{
	int	i;

	i = 0;
	all->tex = (t_texture *)malloc(sizeof(t_texture) * 4);
	if (!all->tex)
		return (msg_err("init_tex", "malloc failed", 2));
	while (i < 4)
	{
		all->tex[i].dir = NULL;
		all->tex[i].img = NULL;
		all->tex[i].height = 0;
		all->tex[i].width = 0;
		all->tex[i].addr = NULL;
		all->tex[i].bpp = 0;
		all->tex[i].endian = 0;
		all->tex[i].line_len = 0;
		i++;
	}
	return (0);
}

void	init_map(t_map *map)
{
	map->line = NULL;
	map->x = 0;
	map->y = 0;
}

void	init_px(t_all *all)
{
	all->img_px.addr = NULL;
	all->img_px.bpp = 0;
	all->img_px.endian = 0;
	all->img_px.line_len = 0;
	all->img_px.mlx_img = NULL;
	all->img_px.c = 0;
	all->img_px.f = 0;
}

void	init_ray(t_all *all)
{
	all->ray.r_dir_x = 0;
	all->ray.r_dir_y = 0;
	all->ray.orient_x = 0;
	all->ray.orient_y = 0;
	all->ray.plane_x = 0.00;
	all->ray.plane_y = 0.00;
	all->ray.dist_x = 0;
	all->ray.dist_y = 0;
	all->ray.delta_dist_x = 0;
	all->ray.delta_dist_y = 0;
	all->ray.draw_start = 0;
	all->ray.draw_end = 0;
	all->ray.side = -1;
	all->ray.dir_tex = 0;
	all->ray.tex_x = 0;
	all->ray.tex_y = 0;
	all->ray.wall_height = 0;
}
