/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:21:49 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/06 17:27:55 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** possible to add another skips like"|| line[*i] == '\t' || line[*i] == '\v'
** || line[*i] == '\f' || line[*i] == '\r') // a confirmer
*/
int	ft_skip(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\n'))
		(*i)++;
	return (0);
}

int	ft_skip_char(char *line, int *i, char c)
{
	int	j;

	j = 0;
	while (line[*i] != c)
	{
		j++;
		(*i)++;
	}
	return (j);
}
