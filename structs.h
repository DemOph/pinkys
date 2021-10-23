/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:13:14 by chael-ha          #+#    #+#             */
/*   Updated: 2021/10/22 16:04:30 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
#include <math.h>

int player;

#define WALL_SIZE 64
#define PLAYER_SIZE 32

# define PI			3.14159265359
# define FOV_ANGLE = 60 * (Math.PI / 180);
# define WINDOW_STRIP_WIDTH = 1; //so that u can see column bigger than the picxel//thickness of the wall hh
# define NUM_RAYS = WINDOW_WIDTH / WALL_STRIP_WIDTH;
# define SIZE		42
# define UP_KEY		13
# define DOWN_KEY	1
# define RIGHT_KEY	2
# define LEFT_KEY	0
# define LEFT_ARROW	123
# define RIGHT_ARROW	124
# define ESC		53
# define false		0
#include "structs.h"


typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct s_texture{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
	
}				t_texture;

typedef struct		s_window
{
	int				width;
	int				height;
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
}                   t_window;

typedef struct		s_coor
{
	int				x;
	int				y;
}					t_coor;

typedef struct		s_d_coor
{
	double			x;
	double			y;
}					t_d_coor;

typedef struct s_player
{
	t_coor			player_coor;
	t_d_coor		player_world_coor;
	t_d_coor		orientation_ray;
	double			orientation;
}					t_player;

typedef struct		s_check_params
{
	int				player_count;
	int				screen_done;
	int				floor_done;
	int				ceiling_done;
	int				no_tex_done;
	int				so_tex_done;
	int				ea_tex_done;
	int				we_tex_done;
	int				floor_color;
	int				ceiling_color;
}					t_check_params;

typedef	struct		s_mlx
{
	t_window		win;
	t_player		player;
	int				max_x;
	int				max_y;
	char			**lines;
	char			**virgin_map;
	char			**map_had6;
	t_texture		screen_img;
	t_texture		w_no_text;
	t_texture		w_so_text;
	t_texture		w_we_text;
	t_texture		w_ea_text;
}					t_mlx;

int					ft_atoi(const char *str);
char				**readmap(char *filename, t_mlx *mlx, t_check_params *ch);
void    			ft_init_params(t_mlx *mlx, t_check_params *ch);
void				ft_put_error(char *str, t_mlx *mlx);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				draw_map(t_mlx *mlx);
void				my_mlx_pixel_put(t_texture *text, int x, int y, int color);
int					ft_exit(void);
void				verify_params(t_mlx *mlx, t_check_params *ch);
void				read_path(int num, char *str, t_mlx *mlx, t_check_params *ch);
void				test_param(char *str, t_mlx *mlx, char *string);
void				read_resolution(char *s, t_mlx *mlx, t_check_params *ch);
int					read_rgb(char *s, t_mlx *mlx);
int					which_param(char c,  char *str, t_mlx *mlx, t_check_params *ch);
void				read_cf_color(char *s, t_check_params *ch, t_mlx *mlx, char type);
char				**get_map_lines(char **lines, char **tmp, int fd);
int 				countx(t_mlx *mlx);
int					county(t_mlx *mlx);
void				manage_player(t_mlx *mlx, t_check_params *ch);


t_d_coor	ft_normalise_vector_2d(t_d_coor vector);
t_d_coor	ft_scale_vector_2d(t_d_coor vector2D, double scale);
t_d_coor	ft_sub_vector_2d(t_d_coor vector2D, t_d_coor second_vector2D);
t_d_coor	ft_add_vector_2d(t_d_coor vector2D, t_d_coor second_vector2D);
t_d_coor	ft_angle_to_2d_vector(double alpha);

#endif
