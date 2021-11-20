/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:14:23 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/20 21:08:25 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
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

struct	s_mlx
{
	void			*mlx;
	void			*mlx_win;
	struct s_map	map;
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
int		mlx_close(void);
int		mlx_press(int key);

#endif
