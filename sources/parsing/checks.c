/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:16 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/16 22:02:24 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file_path(char *pathname)
{
	int	fd;

	if (access(pathname, F_OK) == -1)
	{
		print_error_fd(pathname, "file does not exists", 2);
		return (1);
	}
	if (access(pathname, R_OK) == -1)
	{
		print_error_fd(pathname, "file read denied", 2);
		return (1);
	}
	fd = open(pathname, O_DIRECTORY);
	if (fd != -1)
	{
		close (fd);
		print_error_fd(pathname, "is a directory", 2);
		return (1);
	}
	return (0);
}

static int	check_file_name(char *name, char *base)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
		i++;
	if (i <= 4 || name[i - 1] != base[3] || name[i - 2] != base[2]
		|| name[i - 3] != base[1] || name[i - 4] != base[0])
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
	if (check_file_path(av[1]) != 0)
		return (1);
	if (check_file_name(av[1], ".cub") != 0)
	{
		print_error_fd("Invalid file extension", av[1], 2);
		return (1);
	}
	return (0);
}
