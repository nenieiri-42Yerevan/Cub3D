/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:14:23 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/27 23:21:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define INITIAL_FOV 66 

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "libgnl.h"
# include "mlx.h"
# include "keys.h"
# include "math.h"

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
}		pos;

struct	s_draw
{
	double	move_speed;
	double	rot_speed;
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
}		draw;

struct	s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	struct s_map	map;
	struct s_pos	pos;
	struct s_draw	draw;
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
void	pos_init(void);
void	ray_cast(void);
void	find_delta(int x);
void	find_hit(void);
void	find_draw(void);

#endif
