/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:17:16 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/08 14:56:45 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file_path(char *pathname)
{
	// int	fd;

	if (access(pathname, F_OK) == -1)
		return (msg_err(pathname, "file does not exists !!!", 2));
	if (access(pathname, R_OK) == -1)
		return (msg_err(pathname, "file read denied", 2));
	// fd = open(pathname, O_DIRECTORY);
	// if (fd != -1)
	// {
	// 	close (fd);
	// 	return (msg_err(pathname, "is a directory", 2));
	// }
	return (0);
}
