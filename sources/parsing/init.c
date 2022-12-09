/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:54:37 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/09 17:30:07 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_window *win)
{
	win->pt_mlx = NULL;
	win->pt_win = NULL;
}

static int	ft_init_parse_win(char *av, t_all *all, t_window *win)
{
	if (ft_parse(av, all) == 1)
	{
		free_all(all);
		return (1);
	}
	if (all->map.line == NULL)
		return (1);
	if (create_window(all, win) == 1)
		return (1);
	return (0);
}

int	ft_init(char *av)
{
	t_all		all;
	t_window	win;
	t_map		map;
	t_pos		pos;

	init_win(&win);
	init_map(&map);
	init_pos(&pos);
	if (init_tex(&all) == 1)
		return (1);
	init_px(&all);
	init_ray(&all);
	all.win = win;
	all.doc = NULL;
	all.flag = 0;
	all.map = map;
	all.pos = pos;
	if (ft_init_parse_win(av, &all, &all.win) == 1)
		return (1);
	orientation_p(&all);
	tex_creation(&all);
	loop(&all);
	the_end(&all);
	free_all(&all);
	return (0);
}
