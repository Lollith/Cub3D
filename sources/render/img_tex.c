/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:33:33 by agouet            #+#    #+#             */
/*   Updated: 2022/12/06 18:02:54 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	check_img(t_all *all)
{
	if (all->tex[NORTH].img == NULL)
		return(FALSE);
	return (TRUE);
}



void get_addr(t_all *all)
{
	all->tex[NORTH].addr = mlx_get_data_addr(all->tex[NORTH].img,
			&all->tex[NORTH].bpp, &all->tex[NORTH].line_len,
			&all->tex[NORTH].endian);
}

int	files_to_images(t_all *all)
{
	all->tex[NORTH].img = mlx_xpm_file_to_image(all->win.pt_mlx, all->tex[NORTH].dir, &all->tex[NORTH].width, &all->tex[NORTH].height);
	if (check_img(all) == 0)
	{
		return (FALSE);
	}
	get_addr(all);
	return (TRUE);
}

void ft_distroy_img(t_all *all)
{
	mlx_destroy_image(all->win.pt_mlx, all->tex[NORTH].img);
}