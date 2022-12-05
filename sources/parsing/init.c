/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:54:37 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/05 13:25:38 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_pos(t_pos *pos)
{
	pos->p_x = 0.2;
	pos->p_y = 0.2;
	pos->p = 'P';
	// pos->old_p_x = 0;a supprimer
	// pos->old_p_y = 0;
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

static int	init_tex(t_all *all)
{
	int	i;

	i = 0;
	all->tex = (t_texture *) malloc (sizeof(t_texture) * 4);
	if (!all->tex)
		return (1);
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

static void	init_px(t_all *all)
{
	all->img_px.addr = NULL;
	all->img_px.bpp = 0;
	all->img_px.endian = 0;
	all->img_px.line_len = 0;
	all->img_px.mlx_img = NULL;
	all->img_px.c = 0;
	all->img_px.f = 0;
}

static void	init_ray(t_all *all)
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
}

// position initiale de perso
void	read_pos_ini(t_all *all)
{	
	int	i;

	i = 0;
	while (all->map.line[i])
	{
		if (all->map.line[i] == 'P' || all->map.line[i] == 'S' //a remplacer par N
			|| all->map.line[i] == 'W' || all->map.line[i] == 'E')
		{
			all->pos.p_x = i % (all->map.x);
			all->pos.p_y = i / (all->map.x);
			all->pos.index = i;
		}
		i++;
	}
}

void	orientation_p(t_all *all)
{
	if (all->pos.p == 'P') // a remplacer par  N 
	{
		all->ray.orient_y = -1;
		all->ray.plane_x = 0.60;
	}
	if (all->pos.p == 'S')
	{
		all->ray.orient_y = 1;
		all->ray.plane_x = 0.60;
	}
	if (all->pos.p == 'E')
	{
		all->ray.orient_x = 1;
		all->ray.plane_y = 0.60;
	}
	if (all->pos.p == 'W')
	{
		all->ray.orient_x = -1;
		all->ray.plane_y = 0.60;
	}
}

int	ft_init(char *av)
{
	t_all		all;
	t_window	win;
	t_map		map;
	t_pos		pos;

// printf("ft_init IN\n");//to be deleted
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

	if (ft_parse(av, &all) == 1)
	{
		// free_all(&all);// attention double free ??
		return (1);
	}
	printf("%s\n", all.map.line);
	if (all.map.line == NULL)
		return (1);
	printf("x = %d, y = %d, x *y = %d, len = %zu\n", all.map.x, all.map.y, all.map.x * all.map.y, ft_strlen(all.map.line));
	printf("%s\n", all.map.line);
	create_window(&all.win);
//--------------------------------fonctions---------------------------------
	// creation img minimap
	read_pos_ini(&all);
	orientation_p(&all);
	// creation textures comme img

	files_to_images(&all);
	// commandes
	ft_key_loop_hook(&all);
	//  render
	mlx_loop_hook(all.win.pt_mlx, &render, &all); //boucle sur mes images
//  //-------------------------------ends---------------------------------------
	mlx_loop(all.win.pt_mlx);
	the_end(&all);
	free_all(&all);
	return (0);
}
