/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:49:43 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/21 14:26:22 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parsing_map_by_lines(void)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	while (++i < my_map.map_height)
	{
		j = -1;
		len = ft_strlen(my_map.map[i]);
		if (len == 0)
			return (errors(5));
		while (++j < len)
		{
			if ((i == 0 || (i == my_map.map_height - 1)) && \
					(my_map.map[i][j] != '1' && my_map.map[i][j] != ' '))
				return (errors(6));
			else if (i != 0 && (i != my_map.map_height - 1) && \
							my_map.map[i][j] != ' ')
				break ;
		}
		if (i != 0 && (i != my_map.map_height - 1) && j == len)
			return (errors(5));
	}
	return (0);
}

static int	parsing_player(size_t i, size_t j)
{
	static int	n_s_e_w = 0;

	if (my_map.map[i][j] == 'N' || my_map.map[i][j] == 'S' || \
			my_map.map[i][j] == 'E' || my_map.map[i][j] == 'W')
	{
		my_map.dir = my_map.map[i][j];
		pos.map_x = j;
		pos.map_y = i;
		n_s_e_w++;
	}
	if (n_s_e_w > 1)
		return (errors(8));
	return (0);
}

static int	parsing_map_inner(void)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (++i < my_map.map_height)
	{
		j = -1;
		len = ft_strlen(my_map.map[i]);
		while (++j < len)
		{
			if (my_map.map[i][j] == '1' || my_map.map[i][j] == ' ')
				continue ;
			else if (my_map.map[i][j] == '0' || my_map.map[i][j] == '2' || \
					my_map.map[i][j] == 'N' || my_map.map[i][j] == 'S' || \
					my_map.map[i][j] == 'E' || my_map.map[i][j] == 'W')
			{
				if (parsing_player(i, j) == 1 || parsing_by_cross(i, j) == 1)
					return (1);
			}
			else
				return (errors(7));
		}
	}
	return (0);
}

int	parsing_map(char ***map, size_t map_height)
{
	my_map.fr = 500;
	my_map.fg = 500;
	my_map.fb = 500;
	my_map.cr = 500;
	my_map.cg = 500;
	my_map.cb = 500;
	if (parsing_map_settings(map, map_height) == 0)
	{
		if (settings_checker() == 1 || parsing_map_by_lines() == 1)
			return (1);
		if (parsing_map_inner() == 1)
			return (1);
		if (!(my_map.dir == 'N' || my_map.dir == 'S' || my_map.dir == 'E' || \
				my_map.dir == 'W'))
			return (errors(9));
		return (0);
	}
	return (1);
}
