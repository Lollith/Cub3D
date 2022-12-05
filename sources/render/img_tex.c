/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:33:33 by agouet            #+#    #+#             */
/*   Updated: 2022/12/04 17:21:17 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
int	check_img(t_all *all)
{
	if (all->tex[NORTH].img == NULL)
		return(FALSE);
	return (TRUE);
}

int	files_to_images(t_all *all)
{
	all->tex[NORTH].img = mlx_xpm_file_to_image(all->win.pt_mlx, all->tex[NORTH].dir, &all->tex[NORTH].width, &all->tex[NORTH].height);
	if (check_img(all))
	{
		return (FALSE);
	}
	return (TRUE);
}

void get_addr(t_all *all)
{
	all->tex[NORTH].addr = mlx_get_data_addr(all->tex[NORTH].img,
			&all->img_px.bpp, &all->img_px.line_len,
			&all->img_px.endian);
}

void ft_distroy_img(t_all *all)
{
	mlx_destroy_image(all->win.pt_mlx, all->tex[NORTH].img);
}