/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:16 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/07 15:07:14 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_path(char *pathname)
{
	int	fd;

	if (access(pathname, F_OK) == -1)
		return (print_error_fd(pathname, "file does not exists", 2));
	if (access(pathname, R_OK) == -1)
		return (print_error_fd(pathname, "file read denied", 2));
	fd = open(pathname, O_DIRECTORY);
	if (fd != -1)
	{
		close (fd);
		return (print_error_fd(pathname, "is a directory", 2));
	}
	return (0);
}

static int	check_file_name(char *name, char *base)
{
	int	i;
	int	j;

	i = ft_strlen(name) - 1;
	j = ft_strlen(base) - 1;
	if (i <= j || name[i - j - 1] == '/')
		return (1);
	while (j >= 0)
	{
		if (name[i] != base[j])
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	if (ac != 2)
		return (print_error_fd("Invalid number of arguments", NULL, 2));
	if (check_file_path(av[1]) != 0)
		return (1);
	if (check_file_name(av[1], ".cub") != 0)
		return (print_error_fd("Invalid file extension", av[1], 2));
	return (0);
}
