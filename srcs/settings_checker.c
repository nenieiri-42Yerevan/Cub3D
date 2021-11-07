/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:50:58 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/31 22:52:37 by vismaily         ###   ########.fr       */
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
	if (my_map.f == NULL)
		return (errors_settings(7));
	if (my_map.c == NULL)
		return (errors_settings(8));
	return (0);
}
