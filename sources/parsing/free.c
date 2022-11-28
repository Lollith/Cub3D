/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:50:33 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/25 17:55:11 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all(t_all *all)
{
	if (all != NULL)
	{
		if (all->tex.n != NULL)
			free(all->tex.n);
		if (all->tex.s != NULL)
			free(all->tex.s);
		if (all->tex.w != NULL)
			free(all->tex.w);
		if (all->tex.e != NULL)
			free(all->tex.e);
		if (all->map.line != NULL)
			free(all->map.line);
	}
	return (0);
}