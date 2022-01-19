/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:28:22 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/15 23:12:54 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_path(char **str, char **set_var)
{
	int	i;

	i = 2;
	if (ft_isspace((*str)[2]) == 1)
		i = 3;
	*set_var = ft_strtrim(&(*str)[i], " \t");
	if ((ft_strlen(*set_var) == 0) || (ft_strchr(*set_var, ' ') != NULL) || \
			(ft_strchr(*set_var, '\t')))
	{
		free(*set_var);
		return (errors_param(1, (*str)));
	}
	return (0);
}

static int	paths_two(char ***map, int i, int **duplicates)
{
	if ((*map)[i][0] == 'E' && (*map)[i][1] == 'A' && \
			ft_isspace((*map)[i][2]) == 1)
	{
		(*duplicates)[4]++;
		return (get_path(&(*map)[i], &my_map.ea));
	}
	else if ((*map)[i][0] == 'S' && ft_isspace((*map)[i][1]) == 1)
	{
		(*duplicates)[5]++;
		return (get_path(&(*map)[i], &my_map.s));
	}
	else if ((*map)[i][0] == 'F' && ft_isspace((*map)[i][1]) == 1)
	{
		(*duplicates)[6]++;
		return (parsing_color(&(*map)[i], 'f'));
	}
	else if ((*map)[i][0] == 'C' && ft_isspace((*map)[i][1]) == 1)
	{
		(*duplicates)[7]++;
		return (parsing_color(&(*map)[i], 'c'));
	}
	return (-1);
}

static int	paths(char ***map, int i, int **duplicates)
{
	if ((*map)[i][0] == 'R' && ft_isspace((*map)[i][1]) == 1)
	{
		(*duplicates)[0]++;
		return (parsing_resolution(&(*map)[i], &my_map.r_x, &my_map.r_y));
	}
	if ((*map)[i][0] == 'N' && (*map)[i][1] == 'O' && \
			ft_isspace((*map)[i][2]) == 1)
	{
		(*duplicates)[1]++;
		return (get_path(&(*map)[i], &my_map.no));
	}
	else if ((*map)[i][0] == 'S' && (*map)[i][1] == 'O' && \
			ft_isspace((*map)[i][2]) == 1)
	{
		(*duplicates)[2]++;
		return (get_path(&(*map)[i], &my_map.so));
	}
	else if ((*map)[i][0] == 'W' && (*map)[i][1] == 'E' && \
			ft_isspace((*map)[i][2]) == 1)
	{
		(*duplicates)[3]++;
		return (get_path(&(*map)[i], &my_map.we));
	}
	else
		return (paths_two(map, i, duplicates));
}	

static void	init(size_t *i, int *result, int **duplicates)
{	
	*i = -1;
	*result = 0;
	my_map.r_x = 0;
	my_map.r_y = 0;
	*duplicates = malloc(sizeof(int) * 8);
	if (*duplicates == 0)
		exit(1);
	ft_memset(*duplicates, 0, 8 * sizeof(int));
}

int	parsing_map_settings(char ***map, size_t map_height)
{
	size_t	i;
	int		result;
	int		*duplicates;
	int		ret;


	init(&i, &result, &duplicates);
	while (++i < map_height)
	{
		result = paths(map, i, &duplicates);
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
	ret = check_duplicates(duplicates);
	free(duplicates);
	return (ret); 
}
