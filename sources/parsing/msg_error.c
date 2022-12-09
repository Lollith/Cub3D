/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:27:19 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/09 11:34:49 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	print_str(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		i += write(fd, &s[i], 1);
	return (i);
}

int	msg_err(char *s1, char *s2, int fd)
{
	int	i;

	i = 0;
	i = print_str("Error\n", fd);
	i += print_str(s1, fd);
	if (s2)
	{
		i += write(fd, ": ", 2);
		i += print_str(s2, fd);
	}
	else
		i += write(fd, "\n", 1);
	return(1);
}

// int	print_error_fd(char *s1, char *s2, int fd)
// {
// 	int	i;

// 	i = 0;
// 	i = print_str("Error\n", fd);
// 	i += print_str(s1, fd);
// 	if (s2)
// 	{
// 		i += write(fd, ": ", 2);
// 		i += print_str(s2, fd);
// 	}
// 	i += write(fd, "\n", 1);
// 	// return (i);
// 	return(1);
// }

// int	msg_err(char *s1, char *s2, int fd)
// {
	
// }