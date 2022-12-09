/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:44:56 by esmirnov          #+#    #+#             */
/*   Updated: 2022/12/09 16:07:22 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_open_file(char *av, int *fd, char *file_extension)
{
	*fd = open(av, O_DIRECTORY);
	if (*fd != -1)
	{
		close (*fd);
		return (msg_err(av, "is a directory", 2));
	}
	*fd = open(av, O_RDONLY);
	if (*fd < 0 || *fd == 2 || *fd > FD_MAX)
	{
		if (*fd == 2 || *fd > FD_MAX)
			close (*fd);
		perror("Error\nft_open_file: ");
		write(2, av, ft_strlen(av));
		write(2, "\n", 1);
		return (1);
	}
	if (check_file_name(av, file_extension) != 0)
	{
		close (*fd);
		return (msg_err("ft_open_file: invalid file extension", av, 2));
	}
	return (0);
}

static char	*ft_get_first_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		get_next_line(-1);
		msg_err("ft_get_first_line: invalid file", NULL, 2);
		return (NULL);
	}
	return (line);
}

static int	ft_get_img_color_map(char *line, t_all *all)
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
			ret = ft_get_tex_img(&line[i], all);
		else if (line[i] == 'F' || line[i] == 'C')
			ret = ft_get_tex_color(&line[i], all);
		else if (line[i] == '\0')
			return (0);
		else
			return (msg_err("ft_get_tex_map: invalid line", line, 2));
	}
	else
		ret = ft_get_map(line, &all->map, all);
	return (ret);
}

int	ft_get_info(char *av, t_all *all)
{
	char	*line;
	int		fd;

	fd = -1;
	if (ft_open_file(av, &fd, ".cub") == 1)
		return (1);
	line = ft_get_first_line(fd);
	while (line)
	{
		if (ft_get_img_color_map(line, all) == 1)
		{
			get_next_line(-1);
			free (line);
			close (fd);
			return (1);
		}
		free (line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	close (fd);
	return (0);
}

int	ft_parse(char *av, t_all *all)
{
	if (ft_get_info(av, all) == 1)
		return (1);
	if (ft_check_map(&all->map, all) == 1)
		return (1);
	return (0);
}
