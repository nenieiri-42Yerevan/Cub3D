/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:28:22 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/03 21:39:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_path(char **str, char **set_var)
{
	int	i;

	i = 2;
	if (ft_isspace((*str)[2]) == 1)
		i = 3;
	*set_var = ft_strtrim(&(*str)[i], " ");
	*set_var = ft_strtrim(&(*str)[i], "\t");
	if ((ft_strlen(*set_var) == 0) || (ft_strchr(*set_var, ' ') != NULL) || \
			(ft_strchr(*set_var, '\t')))
		return (errors_param(1, (*str)));
	return (0);
}

static int	paths(char ***map, int i)
{
	if ((*map)[i][0] == 'R' && ft_isspace((*map)[i][1]) == 1)
		return (parsing_resolution(&(*map)[i], &my_map.r_x, &my_map.r_y));
	if ((*map)[i][0] == 'N' && (*map)[i][1] == 'O' && \
			ft_isspace((*map)[i][2]) == 1)
		return (get_path(&(*map)[i], &my_map.no));
	else if ((*map)[i][0] == 'S' && (*map)[i][1] == 'O' && \
			ft_isspace((*map)[i][2]) == 1)
		return (get_path(&(*map)[i], &my_map.so));
	else if ((*map)[i][0] == 'W' && (*map)[i][1] == 'E' && \
			ft_isspace((*map)[i][2]) == 1)
		return (get_path(&(*map)[i], &my_map.we));
	else if ((*map)[i][0] == 'E' && (*map)[i][1] == 'A' && \
			ft_isspace((*map)[i][2]) == 1)
		 return (get_path(&(*map)[i], &my_map.ea));
	else if ((*map)[i][0] == 'S' && ft_isspace((*map)[i][1]) == 1)
		 return (get_path(&(*map)[i], &my_map.s));
	else if ((*map)[i][0] == 'F' && ft_isspace((*map)[i][1]) == 1)
		 return (get_path(&(*map)[i], &my_map.f));
	else if ((*map)[i][0] == 'C' && ft_isspace((*map)[i][1]) == 1)
		 return (get_path(&(*map)[i], &my_map.c));
	return (-1);
}	

int	parsing_map_settings(char ***map, size_t map_height)
{
	size_t	i;
	int		result;

	i = -1;
	result = 0;
	my_map.r_x = 0;
	my_map.r_y = 0;
	while (++i < map_height)
	{
		result = paths(map, i);
		if (result == -1)
		{
			if (ft_strlen((*map)[i]) == 0)
				continue ;
			else
			{
				my_map.map = &(*map)[i];
				my_map.map_height = map_height - i;
				break ;
			}
		}
		else if (result == 1)
			return (1);
	}
	return (0);
}
