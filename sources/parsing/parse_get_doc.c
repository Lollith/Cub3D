/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:26:15 by esmirnov          #+#    #+#             */
/*   Updated: 2022/11/18 16:32:13 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_nb(int fd)
{
	char	*line;
	int		nb;

	line = NULL;
	nb = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free (line);
		nb++;
	}
	return (nb);
}

static int	ft_nb_lines(char *av)
{
	int		nb;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
	{
		print_error_fd("ft_nb_lines: open: invalid fd", NULL, 2);
		return (1);
	}
	nb = ft_get_nb(fd);
	close (fd);
	if (nb < 9)
	{
		print_error_fd("ft_nb_lines: incorrect doc or gnl failed", NULL, 2);
		return (1);
	}
	return (nb);
}

static void	ft_fill_doc(int fd, int nb, t_all *all)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i <= nb)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all->doc[i] = line;
		i++;
	}
	all->doc[i] = '\0';
}

static int	ft_file_cpy(char *av, int nb, t_all *all)
{
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0 || fd == 2 || fd > FD_MAX)
	{
		print_error_fd("ft_file_cpy: invalid fd", NULL, 2);
		return (1);
	}
	all->doc = (char **)malloc(sizeof(char *) * (nb));
	if (!all->doc)
	{
		print_error_fd("ft_file_cpy: malloc failed", NULL, 2);
		return (1);
	}
	ft_fill_doc(fd, nb, all);
	close (fd);
	return (0);
}

int	ft_file_read(char *av, t_all *all)
{
	int		nb_lines;

	nb_lines = ft_nb_lines(av);
	printf("nb of line is %d\n", nb_lines);
	if (nb_lines < 9)
		return (1);
	if (ft_file_cpy(av, nb_lines, all) == 1)
		return (1);
	return (0);
}
