/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:16 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/15 15:40:01 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file_name(char *name)
{
	int	i;

	i = 0;
	while(name[i])
		i++;
	if (i > 4 || name[i] != 'b' || name[i - 1] != 'u' || name[i - 2] != 'c' ||
		name[i - 3] != '.')
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
	if (check_file_name(av[1]) != 0)
	{
		print_error_fd("Invalid file name", av[1], 2);
		return (1);
	}
	return (0);
}

//chek to open?