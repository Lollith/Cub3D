/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/24 18:47:32 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_parse(char *av, t_all *all)
{
	if (ft_get_info(av, all) == 1)
		return (1);
	return (0);
}

// static void	print_doc(t_all *all)
// {
// 	int	i;

// 	i = 0;
// 	while (all->doc[i] != NULL)
// 	{
// 		printf("%s", all->doc[i]);
// 		i++;
// 	}
// }
// int	ft_parse(char *av, t_all *all)
// {
// 	if (ft_file_read(av, all) == 1)
// 		return (1);
// 	print_doc(all);//to be deleted
// 	if (ft_texture(&all->tex, all->doc, all) == 1)
// 		return (1);
// 	// all->map.line = ft_map(all->doc);//a voir pour return (1) ou non
// 	return (0);
// }

// ft_map_read_check(data);
// think free doc
