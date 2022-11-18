/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/18 14:39:05 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	ft_file_read(char *av, t_all *all)
// {
// 	// int		fd;
// 	// // int		i;
// 	// // char	*line;

// 	// fd = open(av[1], O_RDONLY);
// 	// if (fd < 0 || fd == 2 || fd > FD_MAX)
// 	// 	print_error_fd("map_read: invalid fd", NULL, 2);
		
// 	// // data->map = (char **)malloc(sizeof(char *) * (data->map_y));
// 	// // if (!data->map)
// 	// // 	ft_print_error("map_read: data->map malloc failed\n", data);
// 	// // ft_data_map_i_init(data);
// 	// // i = 0;
// 	// // while (i <= data->map_y)
// 	// // {
// 	// // 	line = get_next_line(fd);
// 	// // 	if (line == NULL)
// 	// // 		break ;
// 	// // 	data->map[i] = line;
// 	// // 	i++;
// 	// // }
// 	// close (fd);
// 	// // ft_map_read_check(data);
// }

int	ft_parse(char *av, t_all *all)
{
	// ft_file_read(av, all);
	(void)av;
	(void)all;
	return (0);
}