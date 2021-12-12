/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:14:23 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/12 23:21:47 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define INITIAL_FOV 60 
# define NO_WALL "0NSWE"

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "libgnl.h"
# include "mlx.h"
# include "keys.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

struct	s_map
{
	int		r_x;
	int		r_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		fr;
	int		fg;
	int		fb;
	int		cr;
	int		cg;
	int		cb;
	char	dir;
	char	**map;
	size_t	map_height;
}		my_map;

struct	s_textures
{
	int		tex_width;
	int		tex_height;
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
	t_data	s;
};

struct	s_pos
{
	int		angle;
	int		map_x;
	int		map_y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera;
	double	ray_dir_x;
	double	ray_dir_y;
	double	ray_dir;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	int		side;
};

struct	s_draw
{
	double	move_speed;
	double	rot_speed;
	double	wall_dist;
	double	hit_point;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	t_data	tex;
	int		line_height;
	int		draw_start;
	int		draw_end;
};

typedef struct	s_sprite
{
	double	x;
	double	y;
	char	texture;
	double	dist;
	double	transform_x;
	double	transform_y;
	int		draw_start_x;
	int		draw_end_x;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		sprite_height;
	int		sprite_screen_x;
}				t_sprite;

struct	s_sprites
{
	double		*perp_dists;
	int			count;
	t_sprite	*sprites;
};

struct	s_keys
{
	int	a;
	int	d;
	int	w;
	int	s;
	int	right;
	int	left;
};

struct	s_mlx
{
	void				*mlx;
	void				*mlx_win;
	t_data				img;
	struct s_map		map;
	struct s_pos		pos;
	struct s_draw		draw;
	struct s_keys		keys;
	struct s_sprites	sprites;
	struct s_textures	textures;
}		game;

int		errors(int n);
int		errors_param(int n, char *str);
int		errors_settings(int n);
int		settings_checker(void);
int		check_duplicates(int *duplicates);
int		parsing_map(char ***map, size_t map_height);
int		parsing_map_settings(char ***map, size_t map_height);
int		parsing_resolution(char **str, int *r_x, int *r_y);
int		parsing_by_cross(size_t i, size_t j);
int		parsing_color(char **str, char c);
int		cub3d(void);
void	put_pixel(t_data *data, int x, int y, int color);
int		get_color(t_data *data, int x, int y);
int		creat_trgb(int t, int r, int g, int b);
int		mlx_close(void);
int		mlx_press(int key);
int		mlx_release(int key);
void	pos_init(void);
int		ray_cast(void);
void	find_delta(int x);
void	find_hit(void);
void	find_draw(void);
void	draw(int *x, int *y);
void	move(void);
void	rotate(void);
void	textures(void);
void	sprites_array(void);
void	sprites_sort(void);
void	draw_sprites(void);

#endif
