/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:07:10 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/13 20:30:20 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parsing_two(char *set_var, char **color, int i, char line_end)
{
	(*color)[i] = set_var[i];
	if (set_var[i + 1] == line_end)
		(*color)[i + 1] = '\0';
	else if (set_var[i + 1] >= '0' && set_var[i + 1])
	{
		(*color)[i + 1] = set_var[i + 1];
		if (set_var[i + 2] == line_end)
			(*color)[i + 2] = '\0';
		else if (set_var[i + 2] >= '0' && set_var[i + 2] <= '9')
		{
			(*color)[i + 2] = set_var[i + 2];
			if (set_var[i + 3] == line_end)
				(*color)[i + 3] = '\0';
			else
				return (errors_param(2, set_var));
		}
		else
			return (errors_param(2, set_var));
	}
	else
		return (errors_param(2, set_var));
	return (0);
}

static int	parsing_one(char *set_var, int *map_var, char line_end)
{
	char	*color;

	color = malloc(sizeof(char) * 4);
	if (color == NULL)
		return (1);
	color[3] = '\0';
	if (set_var[0] == '0' && set_var[1] == line_end)
			*map_var = 0;
	else if (set_var[0] >= '1' && set_var[0] <= '9')
	{
		if (parsing_two(set_var, &color, 0, line_end) == 0)
			*map_var = ft_atoi(color);
	}
	else
	{
		free(color);
		return (errors_param(2, set_var));
	}
	free(color);
	return (0);
}

static int	parsing_f(char *set_var)
{
	char	*colon;

	if (parsing_one(set_var, &my_map.fr, ',') == 0)
	{
		colon = ft_strchr(set_var, ',') + 1;
		if (parsing_one(colon, &my_map.fg, ',') == 0)
		{
			colon = ft_strchr(colon, ',') + 1;
			if (parsing_one(colon, &my_map.fb, '\0') == 0)
				return (0);
		}
	}
	return (1);
}

int	parsing_color(char **str, char c)
{
	char	*set_var;
	char	*colon;
	int		result;

	result = 0;
	set_var = ft_strtrim(&(*str)[2], " \t");
	if (c == 'c')
	{
		if (parsing_one(set_var, &my_map.cr, ',') == 0)
		{
			colon = ft_strchr(set_var, ',') + 1;
			if (parsing_one(colon, &my_map.cg, ',') == 0)
			{
				colon = ft_strchr(colon, ',') + 1;
				if (parsing_one(colon, &my_map.cb, '\0') == 0)
				{
					free(set_var);
					return (result);
				}
			}
		}
	}
	else
	{
		result = parsing_f(set_var);
		free(set_var);
		return (result);
	}
	free(set_var);
	return (1);
}
