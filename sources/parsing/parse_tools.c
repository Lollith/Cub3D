/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:21:49 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/02 17:00:40 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_skip(char *line, int *i)
{
	while (line[*i] && (line[*i] == ' ' || line[*i] == '\n'))//|| line[*i] == '\t' || line[*i] == '\v' || line[*i] == '\f' || line[*i] == '\r') // a confirmer
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
