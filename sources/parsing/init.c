/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:54:37 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/28 16:34:00 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pos(t_pos *pos)
{
	pos->p_x = 0;
	pos->p_y = 0;
	pos->p = 'P';
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

int	ft_init(char *av)
{
	t_all		all;
	t_window	win;
	t_map		map;
	t_texture	tex;
	t_pos		pos;

printf("ft_init IN\n");//to be deleted
	init_win(&win);
	init_map(&map);
	init_pos(&pos);
	init_tex(&tex);
	init_minimap(&all);
	all.win = win;
	all.doc = NULL;
	all.flag = 0;
	all.map = map;
	all.tex = tex;
	all.pos = pos;
	if (ft_parse(av, &all) == 1)
	{
		free_all(&all);
		return (1);
	}
	free_all(&all);
	return (0);
}
