/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:05:01 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/22 22:53:55 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parsing_r_y(char *trim_str, int *r_x, int *r_y)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(trim_str) && trim_str[i] >= '0' \
			&& trim_str[i] <= '9')
		;
	if (trim_str[i] == '\0')
		*r_y = ft_atoi(&trim_str[0]);
	else if (ft_isspace(trim_str[i]) == 1)
	{
		free(trim_str);
		return (errors(3));
	}
	else
	{
		free(trim_str);
		return (errors(2));
	}
	free(trim_str);
	if (!(*r_y >= 480 && *r_y <= 2160) || !(*r_x >= 640 && *r_x <= 4096))
		return (errors(4));
	return (0);
}

static int	parsing_r_x(char *trim_str, int *r_x, size_t i)
{
	if (ft_isspace(trim_str[i]) == 1)
	{
		trim_str[i] = '\0';
		*r_x = ft_atoi(&trim_str[0]);
	}
	else if (trim_str[i] == '\0')
	{	
		free(trim_str);
		return (errors(2));
	}
	else
	{
		free(trim_str);
		return (errors(1));
	}
	if (ft_strlen(trim_str) == 0)
	{
		free(trim_str);
		return (errors(3));
	}
	return (0);
}

int	parsing_resolution(char **str, int *r_x, int *r_y)
{
	char	*trim_str;
	char	*tmp;
	size_t	i;
	int		res;

	trim_str = ft_strtrim(&(*str)[2], " ");
	i = -1;
	while (++i < ft_strlen(trim_str) && trim_str[i] >= '0' \
			&& trim_str[i] <= '9')
		;
	res = parsing_r_x(trim_str, r_x, i);
	if (res == 1)
		return (1);
	if (ft_strlen(&trim_str[i + 1]) != 0)
	{
		tmp = ft_strtrim(&trim_str[i + 1], " ");
		free(trim_str);
	}
	else
	{	
		free(trim_str);
		return (errors(2));
	}
	return (parsing_r_y(tmp, r_x, r_y));
}
