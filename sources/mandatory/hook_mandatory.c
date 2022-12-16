/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/16 16:04:15 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop(t_all *all)
{
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress, all);
	mlx_hook(all->win.pt_win, KEYRELEASE, 1L << 1, keyrelease, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
	mlx_loop_hook(all->win.pt_mlx, &render, all);
	mlx_loop(all->win.pt_mlx);
}