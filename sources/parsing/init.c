/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:54:37 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/17 11:20:05 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_window *win)
{
	win->pt_mlx = NULL;
	win->pt_win = NULL;
	win->mouse_position = W_WIDTH / 2;
}

static int	ft_init_creation(char *av, t_all *all, t_window *win)
{
	if (W_HEIGHT <= 0 || W_WIDTH <= 0)
		return (msg_err("Wrong size of window", NULL, 2));
	if (ft_parse(av, all) == 1)
	{
		free_all(all);
		return (1);
	}
	if (all->map.line == NULL)
		return (1);
	if (create_window(all, win) == 1)
		return (1);
	orientation_p(all);
	if (tex_creation(all) == 1)
	{
		the_end(all);
		free_all(all);
		return (1);
	}
	return (0);
}

void	init_key(t_all *all)
{
	all->key.up = 0;
	all->key.down = 0;
	all->key.left = 0;
	all->key.right = 0;
	all->key.rot_left = 0;
	all->key.rot_right = 0;
	all->key.esc = 0;
	all->key.mouse_left = 0;
	all->key.mouse_right = 0;
	all->key.m_x = 0;
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
	init_key(&all);
	all.win = win;
	all.doc = NULL;
	all.flag = 0;
	all.map = map;
	all.pos = pos;
	if (ft_init_creation(av, &all, &all.win) == 1)
		return (1);
	loop(&all);
	the_end(&all);
	free_all(&all);
	return (0);
}
