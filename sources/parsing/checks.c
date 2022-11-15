/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:16 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/15 18:47:39 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file_name(char *name, char *base)
{
	int	i;

	i = 0;
	while(name[i] != '\0')
		i++;
	if(i > 4 && name[i] == base[3] && name[i - 1] == base[2] 
		&& name[i - 2] == base[1] && name[i - 3] != base[0])
		return (1);
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
	{
		print_error_fd("Invalid number of arguments", NULL, 2);
		return (1);
	}
	if (check_file_name(av[1], ".cub") != 0)
	{
		print_error_fd("Invalid file name", av[1], 2);
		return (1);
	}
	return (0);
}

//check to open?