/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esmirnov <esmirnov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:57 by agouet            #+#    #+#             */
/*   Updated: 2022/12/07 17:02:23 by esmirnov         ###   ########.fr       */
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
# include <math.h>
# include "get_next_line.h"

// # define UP 119
// # define DOWN 115
// # define LEFT 97
// # define RIGHT 100
//# define ESC 65307

# define W_WIDTH 1000
# define W_HEIGHT 500
# define TEX_SIZE 64

# define MAP_CHARS "1 0NSEW\n" // const char in ft_checks_chars

# define MINI_CUB 10
# define MINI_P 0.3
# define MOVE_SPEED 0.05

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# define TRUE 1
# define FALSE 0

# define NONE 0xFF000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define GREY 0x009E9E9E
# define YELLOW 0xFFFFFF00
# define BLACK 0x00000000
// # define T_BLACK 0x1A000000
typedef enum e_dir{
	
	NORTH,
	SOUTH,
	EAST,
	WEST,
}			t_dir;

typedef struct s_window{
	void			*pt_mlx;
	void			*pt_win;
}					t_window;

/*
** p_x & p_y are for player position
** x - nb of columns, y - nb of lines
*/
typedef struct s_pos
{
	double			p_x;
	double			p_y;
	char			p;
	int				index; // position i sur ma *line
}					t_pos;

typedef struct s_map
{
	char			*line;
	int				x;
	int				y;
	int				mini_pos;
}					t_map;

typedef struct s_texture
{
	char			*dir;
	void			*img;
	int				width;
	int				height;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				x;
	int				y;
}					t_texture;

typedef struct s_img
{
	unsigned int	c;
	unsigned int	f;
	void			*mlx_img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;


typedef struct s_ray
{
	double	orient_x;
	double	orient_y;
	double	plane_x;
	double	plane_y;
	double	r_dir_x;
	double	r_dir_y;
	double	dist_x;
	double	dist_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		draw_start;
	int		draw_end;
	int		side;
	
}		t_ray;

typedef struct s_all
{
	char			**doc;
	int				flag;
	t_window		win;
	t_map			map;
	t_img			img_px;
	t_texture		*tex;
	t_pos			pos;
	t_ray			ray;
}					t_all;

/*-----------------------------------ARGS------------------------------------*/
int		check_args(int ac, char **av);
int		check_file_path(char *pathname);
int		ft_init(char *av);
/*----------------------------------------------------------------------------*/

/*-----------------------------------PARSE------------------------------------*/
int		ft_scan_map(t_map *map, t_all *all);
int		ft_check_map(t_map *map, t_all *all);
int		ft_parse_map(t_map *map);
int		ft_get_map(char *line, t_map *map, t_all *all);
// int		ft_get_tex_color(t_texture *tex, char *line, t_all *all);
// int		ft_get_tex_img(t_texture *tex, char *line, t_all *all);
int		ft_skip(char *line, int *i);
int		ft_skip_char(char *line, int *i, char c);
int		ft_get_tex_img(char *line, t_all *all);
int		ft_get_tex_color(char *line, t_all *all);
int		ft_get_map(char *line, t_map *map, t_all *all);
int		free_all(t_all *all);
int		ft_get_info(char *av, t_all *all);
int		ft_parse(char *av, t_all *all);
// int		ft_get_color(unsigned int *color, char *line, int *flag); static
// int		ft_get_img_path(char *line, char *path, int *flag); static
// int		ft_file_read(char *av, t_all *all);
// int		ft_texture(t_texture *tex, char **doc, t_all *all);
// char	*ft_find_map(char **doc);
// int		ft_skip(char *line, int *i);
// char	*ft_map(char **doc);
// int		ft_put_color(unsigned int *color, char *line, int *flag);
// int		ft_put_tex(t_texture *tex, char *line, char *path, int *flag);
/*----------------------------------------------------------------------------*/

/*----------------------------------WINDOW------------------------------------*/
int		create_window(t_window *win);
int		keypress_wsad(int keysym, t_all *all);
void	ft_key_loop_hook(t_all *all);
int 	the_end(t_all *all);
int		ft_find_map_begin(char **doc);
/*----------------------------------------------------------------------------*/

/*----------------------------------RENDER------------------------------------*/
void	img_pix(t_img *img, int x, int y, int color);
int		tex_creation(t_all *all);
void	read_pos_ini(t_all *all);
int		render(t_all *all);
void	move(double new_pos_x, double new_pos_y, double sign, t_all *all);
void	rotate(t_all *all, int sign);
void	img_creation(t_all *all);
void	draw_wall(int *pt_i, t_img *img, t_all *all, int color);
void	draw_heroe(t_img *img, t_all *all);
void	draw_ray(t_img *img, t_all *all);
// void	clean_px(t_img *img, t_all *all);
void	ray_direction(t_all *all, int *pt_x);
void	ray_size_in_square(t_all *all);
void	digital_differential_analysis(t_all *a, int *mapx, int *mapy);
void	dda_init(t_all *all, int *map_x, int *map_y);
int		calcul_view(t_all *all, int x);
void	raycasting(t_all *all);
void	ft_distroy_img(t_all *all);
void	files_to_images(t_all *all);

/*----------------------------------------------------------------------------*/

/*------------------------------------MAP-------------------------------------*/
void	map_read(char **av, t_map *map);
int		init_square_map(char **av, t_map *map);
void	map_size(char **av, t_map *map);
/*----------------------------------------------------------------------------*/

/*-----------------------------------UTILS------------------------------------*/
// int		ft_atoi(const char *str);
// size_t	ft_strlen(const char *s);//already in gnl folder
char	*ft_strjoin_no_free(char const *s1, char const *s2);
int		msg_err(char *s1, char *s2, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(char *src);
char	*ft_strdup_path(char *src);
void	*ft_memset(void *str, int c, size_t n);
/*----------------------------------------------------------------------------*/

//to be deleted just to start work with raycasting
int		init_square_map(char **av, t_map *map);
#endif