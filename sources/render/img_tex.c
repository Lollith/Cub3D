/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:33:33 by agouet            #+#    #+#             */
/*   Updated: 2022/12/07 13:46:03 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	check_img(t_all *all)
{
	int	i;
	
	i = 0;
	while(i < 4)
	{
		if (all->tex[i].img == NULL)
			return(1);
		i++;
	}
	return (0);
}


void get_addr(t_all *all)
{
	all->tex[NORTH].addr = mlx_get_data_addr(all->tex[NORTH].img,
		&all->tex[NORTH].bpp, &all->tex[NORTH].line_len,
		&all->tex[NORTH].endian);
}

void	files_to_images(t_all *all)
{
	all->tex[NORTH].img = mlx_xpm_file_to_image(all->win.pt_mlx,
		all->tex[NORTH].dir, &all->tex[NORTH].width, &all->tex[NORTH].height);
	all->tex[SOUTH].img = mlx_xpm_file_to_image(all->win.pt_mlx,
		all->tex[SOUTH].dir, &all->tex[SOUTH].width, &all->tex[SOUTH].height);
	all->tex[WEST].img = mlx_xpm_file_to_image(all->win.pt_mlx,
		all->tex[WEST].dir, &all->tex[WEST].width, &all->tex[WEST].height);
	all->tex[EAST].img = mlx_xpm_file_to_image(all->win.pt_mlx,
		all->tex[EAST].dir, &all->tex[EAST].width, &all->tex[EAST].height);
}

int	tex_creation(t_all *all)
{
	files_to_images(all);
	if (check_img(all) == 0)
		return (FALSE);
	get_addr(all);
	return(TRUE);
} 

void ft_distroy_img(t_all *all)
{
	mlx_destroy_image(all->win.pt_mlx, all->tex[NORTH].img);
}