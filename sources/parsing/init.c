/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:54:37 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/18 14:37:33 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pos(t_pos *pos)
{
	pos->p_x = 0;
	pos->p_y = 0;
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
	all.window = win;
	all.map = map;
	all.tex = tex;
	all.pos = pos;
	all.err = 0;
	ft_parse(av, &all);
	return (0);
}
