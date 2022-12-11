/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:52:10 by agouet            #+#    #+#             */
/*   Updated: 2022/12/11 15:05:04 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_loop_hook(t_all *all)
{
	mlx_hook(all->win.pt_win, KEYPRESS, 1L << 0, keypress_wsad, all);
	mlx_key_hook(all->win.pt_win, esc_hook, all);
	mlx_hook(all->win.pt_win, DISTROY, 0, ft_close, &all->win);
}
