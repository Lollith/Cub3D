/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/22 16:58:21 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	ft_parse(char *av, t_all *all)
{
	if (ft_file_read(av, all) == 1)
		return (1);
	// print_doc(all);
	return (0);
}
// ft_map_read_check(data);
// think free doc
