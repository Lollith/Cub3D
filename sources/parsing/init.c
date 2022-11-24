/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:54:37 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/24 13:16:51 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pos(t_pos *pos)
{
	pos->p_x = 0;
	pos->p_y = 0;
	pos->old_p_x = 0;
	pos->old_p_y = 0;
}

static void	init_win(t_window *win)
{
	win->pt_mlx = NULL;
	win->pt_win = NULL;
}

static void	init_map(t_map *map)
{
	map->line = NULL;
	map->x = 0;
	map->y = 0;
}

static void	init_tex(t_texture *tex)
{
	tex->n = NULL;
	tex->s = NULL;
	tex->w = NULL;
	tex->e = NULL;
	tex->c = 0;
	tex->f = 0;
}

static void init_minimap(t_all *all)
{
	all->img_minimap.addr = NULL;
	all->img_minimap.bpp = 0;
	all->img_minimap.endian = 0;
	all->img_minimap.line_len = 0;
	all->img_minimap.mlx_img = NULL;
}

static void init_ray(t_all *all)
{
	all->ray.rayDirX = 0;
	all->ray.rayDirY = 0;
	all->ray.rayDirX = 0;
	all->ray.rayDirY = 0;

}
int	ft_init(char *av)
{
	t_all		all;
	t_window	win;
	t_map		map;
	t_texture	tex;
	t_pos		pos;

	init_win(&win);
	init_map(&map);
	init_pos(&pos);
	init_tex(&tex);
	init_minimap(&all);
	init_ray(&all);
	all.win = win;
	all.doc = NULL;
	all.err = 0;
	all.map = map;
	all.tex = tex;
	all.pos = pos;
	if (ft_parse(av, &all) == 1)
		return (1);
	return (0);
}
