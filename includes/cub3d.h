/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:56:57 by agouet            #+#    #+#             */
/*   Updated: 2022/12/05 10:05:48 by agouet           ###   ########.fr       */
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

# define W_WIDTH 800
# define W_HEIGHT 500

# define MINI_CUB 10
# define MINI_P 0.4
# define MOVE_SPEED 0.1

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
	char			p;
	// double			old_p_x;
	// double			old_p_y;
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

typedef struct s_file
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}			t_file;

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
	
}		t_ray;

typedef struct s_all
{
	char			**doc;
	int				flag;
	t_window		win;
	t_map			map;
	t_img			img_px;
	t_texture		tex;
	t_pos			pos;
	t_ray			ray;
	t_file			file;
}					t_all;

/*-----------------------------------ARGS------------------------------------*/
int		check_args(int ac, char **av);
int		check_file_path(char *pathname);
int		ft_init(char *av);
/*----------------------------------------------------------------------------*/

/*-----------------------------------PARSE------------------------------------*/
int		ft_create_rect_map(t_map *map);
int		ft_skip(char *line, int *i);
int		ft_skip_char(char *line, int *i, char c);
int		ft_get_tex_img(t_texture *tex, char *line, t_all *all);
int		ft_get_tex_color(t_texture *tex, char *line, t_all *all);
int		ft_get_map(char *line, t_map *map, t_all *all);
int		free_all(t_all *all);
int		ft_parse(char *av, t_all *all);
int		ft_get_info(char *av, t_all *all);
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
int		keypress(int keysym, t_all *all);
void	ft_key_loop_hook(t_all *all);
int 	the_end(t_all *all);
int		ft_find_map_begin(char **doc);
/*----------------------------------------------------------------------------*/

/*----------------------------------RENDER------------------------------------*/
void	img_pix(t_img *img, int x, int y, int color);
void	read_pos_ini(t_all *all);
int		render(t_all *all);
void	move(double new_pos_x, double new_pos_y, t_all *all);
void	img_creation(t_all *all);
void	draw_wall(int *pt_i, t_img *img, t_all *all, int color);
void	draw_heroe(t_img *img, t_all *all);
void	draw_ray(t_img *img, t_all *all);
void	clean_px(t_img *img, t_all *all);
void	ray_direction(t_all *all, int *pt_x);
void	ray_size_in_square(t_all *all);
void	digital_differential_analysis(t_all *a, int *mapx, int *mapy, int *s);
void	dda_init(t_all *all, int *map_x, int *map_y);
void	calcul_view(t_all *all, int *side);
void	raycasting(t_all *all);

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
int		print_error_fd(char *s1, char *s2, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(char *src);
char	*ft_strdup_path(char *src);
void	*ft_memset(void *str, int c, size_t n);
/*----------------------------------------------------------------------------*/

//to be deleted just to start work with raycasting
int		init_square_map(char **av, t_map *map);
#endif