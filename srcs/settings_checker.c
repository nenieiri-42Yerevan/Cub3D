/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:50:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/22 22:32:17 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	settings_checker(void)
{
	if (my_map.r_x == 0 || my_map.r_y == 0)
		return (errors_settings(1));
	if (my_map.no == NULL)
		return (errors_settings(2));
	if (my_map.so == NULL)
		return (errors_settings(3));
	if (my_map.we == NULL)
		return (errors_settings(4));
	if (my_map.ea == NULL)
		return (errors_settings(5));
	if (my_map.s == NULL)
		return (errors_settings(6));
	if (!(my_map.fr >= 0 && my_map.fg >= 0 && my_map.fb >= 0 && \
		my_map.fr <= 255 && my_map.fg <= 255 && my_map.fb <= 255))
		return (errors_settings(7));
	if (!(my_map.cr >= 0 && my_map.cg >= 0 && my_map.cb >= 0 && \
		my_map.cr <= 255 && my_map.cg <= 255 && my_map.cb <= 255))
		return (errors_settings(8));
	return (0);
}

int	check_duplicates(int *duplicates)
{
	size_t	len;
	size_t	i;

	len = 8;
	i = 0;
	while (i < len)
	{
		if (duplicates[i] > 1)
		{
			free(duplicates);
			return (errors(10));
		}
		i++;
	}
	free(duplicates);
	return (0);
}
