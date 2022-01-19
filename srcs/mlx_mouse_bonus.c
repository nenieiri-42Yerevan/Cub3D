/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:36:48 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/17 23:37:22 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_mouse(int x, int y, void *param)
{
	(void)param;
	if (game.draw.motion_x != 99999)
	{
		if (OS == 1)
		{
			if (x > 0 && x < game.map.r_x && y > 0 && y < game.map.r_y)
			{
				if (game.draw.motion_x > x)
					mlx_press(KEY_ARROW_LEFT);
				if (game.draw.motion_x < x)
					mlx_press(KEY_ARROW_RIGHT);
			}
		}
		else
		{
			if (game.draw.motion_x > x)
				mlx_press(KEY_ARROW_LEFT);
			if (game.draw.motion_x < x)
				mlx_press(KEY_ARROW_RIGHT);
		}
	}
	game.draw.motion_mouse = 1;
	game.draw.motion_x = x;
	return (0);
}
