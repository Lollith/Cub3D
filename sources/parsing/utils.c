/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:12:01 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/15 16:46:49 by esmirnov         ###   ########.fr       */
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

int	print_error_fd(char *s1, char *s2, int fd)
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
	i += write(fd, "\n", 1);
	return (i);
}

/*
* DESCRIPTION
*	Convert ASCII string to integer
*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str [i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
