/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:30:34 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/23 18:22:53 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_texture(t_texture *tex, char **doc, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (doc[i])
	{
		j = 0;
		ft_skip(doc[i], &j);
		if (doc[i][j] == 'N' && doc[i][j + 1] == 'O')
			ft_put_tex(tex, &doc[i][j + 2], tex->n);
		else if (doc[i][j] == 'S' && doc[i][j + 1] == 'O')
			ft_put_tex(tex, &doc[i][j + 2], tex->n);
		else if (doc[i][j] == 'W' && doc[i][j + 1] == 'E')
			ft_put_tex(tex, &doc[i][j + 2], tex->n);
		else if (doc[i][j] == 'E' && doc[i][j + 1] == 'A')
			ft_put_tex(tex, &doc[i][j + 2], tex->n);
		else if ((doc[i][j] == 'F')
			ft_put_color(tex, &doc[i][j + 2], tex->f);
		else if (doc[i][j] == 'C')
			ft_put_color(tex, &doc[i][j + 2], tex->c);
	}
	if (doc->flag < 6)
		return (1);
	return (0);
}
}