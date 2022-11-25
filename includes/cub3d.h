/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:57 by agouet            #+#    #+#             */
/*   Updated: 2022/11/25 11:58:23 by esmirnov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include "get_next_line.h"

// # define UP 119
// # define DOWN 115
// # define LEFT 97
// # define RIGHT 100
//# define ESC 65307

# define W_WIDTH 800
# define W_HEIGHT 500
# define MINI_SQUARE 20

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# define TRUE 1
# define FALSE 0

# define NONE 0xFF000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_window{
	void			*pt_mlx;
	void			*pt_win;
}					t_window;

/*
** p_x & p_y are for player position
** x - nb of columns, y - nb of lines
** all spaces on the map will be noted as 8
*/
typedef struct s_pos
{
	double			p_x;
	double			p_y;
}					t_pos;

typedef struct s_map
{
	char			*line;
	int				x;
	int				y;
}					t_map;

typedef struct s_texture
{
	char			*n; // p>e unsigned int? attention init a MAJ
	char			*s; // p>e unsigned int? attention init a MAJ
	char			*w; // p>e unsigned int? attention init a MAJ
	char			*e; // p>e unsigned int? attention init a MAJ
	unsigned int	c;
	unsigned int	f;
}					t_texture;

typedef struct s_img
{
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_all
{
	char			**doc;
	int				flag;
	t_window		win;
	t_map			map;
	t_img			img_minimap;
	t_texture		tex;
	t_pos			pos;
}					t_all;

/*-----------------------------------ARGS------------------------------------*/
int		check_args(int ac, char **av);
int		ft_init(char *av);
/*----------------------------------------------------------------------------*/

/*-----------------------------------PARSE------------------------------------*/
int		ft_parse(char *av, t_all *all);
int		ft_get_info(char *av, t_all *all);
int		ft_skip(char *line, int *i);
int		ft_skip_char(char *line, int *i, char c);
int		ft_get_tex_img(t_texture *tex, char *line, t_all *all);
int		ft_get_img_path(char *line, char *path, int *flag);
int		ft_get_tex_color(t_texture *tex, char *line, t_all *all);
int		ft_get_color(int *color, char *line, int *flag);
// int		ft_file_read(char *av, t_all *all);
// int		ft_texture(t_texture *tex, char **doc, t_all *all);
// char	*ft_find_map(char **doc);
// int		ft_skip(char *line, int *i);
// char	*ft_map(char **doc);
// int		ft_put_color(unsigned int *color, char *line, int *flag);
// int		ft_put_tex(t_texture *tex, char *line, char *path, int *flag);
/*----------------------------------------------------------------------------*/

/*----------------------------------WINDOW------------------------------------*/
int		create_window(t_window *data);
void	ft_key_loop_hook(t_window *data);
int 	the_end(t_all *all);
int		ft_find_map_begin(char **doc);
/*----------------------------------------------------------------------------*/

/*----------------------------------RENDER------------------------------------*/
int		render(t_all *all);
/*----------------------------------------------------------------------------*/

/*------------------------------------MAP-------------------------------------*/
void	map_read(char **av, t_map *map);
int		init_square_map(char **av, t_map *map);
void	map_size(char **av, t_map *map);
/*----------------------------------------------------------------------------*/

/*-----------------------------------UTILS------------------------------------*/
int		ft_atoi(const char *str);
char	*ft_strjoin_no_free(char const *s1, char const *s2);
int		print_error_fd(char *s1, char *s2, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
// size_t	ft_strlen(const char *s);//already in gnl folder
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(char *src);
/*----------------------------------------------------------------------------*/

//to be deleted just to start work with raycasting
int		init_square_map(char **av, t_map *map);
#endif