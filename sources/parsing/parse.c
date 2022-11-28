/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/28 14:40:11 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_tex_map(char *line, t_all *all)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;

	if (all->flag < 6)
	{
		ft_skip(&line[i], &i);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			ret = ft_get_tex_img(&all->tex, &line[i], all);
		else if (line[i] == 'F' || line[i] == 'C')
			ret = ft_get_tex_color(&all->tex, &line[i], all);
		else if (line[i] == '\0')
			return (0);
		else
		{
			print_error_fd("ft_get_tex_map: invalide file", NULL, 2);
			return (1);
		}
	}
	else
		ret = ft_get_map(line, &all->map);
	return (ret);
}

int	ft_get_info(char *av, t_all *all)
{
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
	{
		print_error_fd("ft_get_tex_map: invalid fd", NULL, 2);
		return (1);
	}
	line = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL) // a confirmer avec Adeline EOF => NULL et erreur NULL pe check structure vide ou pas et en fonction reagit EOF ou pb de lecture
			break ;
		if (ft_get_tex_map(line, all) == 1)
		{
			free (line);
			close (fd);
			return (1);
		}
		free (line);
	}
	close (fd);
	return (0);
}

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
