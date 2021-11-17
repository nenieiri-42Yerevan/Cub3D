/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_by_cross.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:14:15 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/13 20:33:43 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parsing_bottom(size_t i, size_t j)
{
	size_t	k;
	size_t	len;

	k = i;
	len = my_map.map_height;
	if (i == len - 1 && my_map.map[i][j] != '1' && my_map.map[i][j] != ' ')
		return (errors(6));
	while (++k < len)
	{
		if (my_map.map[k][j] == '1')
			break ;
		else if ((k >= len - 1) || my_map.map[k][j] == ' ')
			return (errors(6));
	}
	return (0);
}

static int	parsing_top(size_t i, size_t j)
{
	int	k;

	k = i;
	if (i == 0 && (my_map.map[i][j] != '1' && my_map.map[i][j] != ' '))
		return (errors(6));
	while (--k >= 0)
	{
		if (my_map.map[k][j] == '1')
			break ;
		else if (k == 0 || my_map.map[k][j] == ' ')
			return (errors(6));
	}
	return (parsing_bottom(i, j));
}

static int	parsing_rigth(size_t i, size_t j)
{
	size_t	k;
	size_t	len;

	k = j;
	len = ft_strlen(my_map.map[i]);
	if (j == len - 1 && my_map.map[i][j] != '1' && my_map.map[i][j] != ' ')
		return (errors(6));
	while (++k < len)
	{
		if (my_map.map[i][k] == '1')
			break ;
		else if ((k >= len - 1) || my_map.map[i][k] == ' ')
			return (errors(6));
	}
	return (parsing_top(i, j));
}

int	parsing_by_cross(size_t i, size_t j)
{
	int	k;

	k = j;
	if (j == 0 && (my_map.map[i][j] != '1' && my_map.map[i][j] != ' '))
		return (errors(6));
	while (--k >= 0)
	{
		if (my_map.map[i][k] == '1')
			break ;
		else if (k == 0 || my_map.map[i][k] == ' ')
			return (errors(6));
	}
	return (parsing_rigth(i, j));
}
