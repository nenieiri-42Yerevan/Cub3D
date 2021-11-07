/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:05:01 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/03 21:09:50 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parsing_r_y(char *trim_str, int *r_x, int *r_y)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(trim_str) && trim_str[i] >= '0' && trim_str[i] < '9')
		;
	if (trim_str[i] == '\0')
		*r_y = ft_atoi(&trim_str[0]);
	else if (ft_isspace(trim_str[i]) == 1)
		return (errors(3));
	else
		return (errors(2));
	if (!(*r_y >= 480 && *r_y <= 2160) || !(*r_x >= 640 && *r_x <= 4096))
		return (errors(4));
	return (0);
}

int	parsing_resolution(char **str, int *r_x, int *r_y)
{
	char	*trim_str;
	size_t	i;

	trim_str = ft_strtrim(&(*str)[2], " ");
	if (ft_strlen(trim_str) == 0)
		return (errors(3));
	i = -1;
	while (++i < ft_strlen(trim_str) && trim_str[i] >= '0' \
			&& trim_str[i] <= '9')
		;
	if (ft_isspace(trim_str[i]) == 1)
	{
		trim_str[i] = '\0';
		*r_x = ft_atoi(&trim_str[0]);
	}
	else if (trim_str[i] == '\0')
		return (errors(2));
	else
		return (errors(1));
	if (ft_strlen(&trim_str[i + 1]) != 0)
		trim_str = ft_strtrim(&trim_str[i + 1], " ");
	else
		return (errors(2));
	return (parsing_r_y(trim_str, r_x, r_y));
}
