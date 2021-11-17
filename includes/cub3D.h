/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:14:23 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/13 21:11:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "libgnl.h"

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
int		cub3D(char ***map, size_t map_height);

#endif
