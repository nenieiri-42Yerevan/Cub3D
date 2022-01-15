/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:36:48 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/15 23:58:45 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_mouse(int x, int y, void *param)
{
	int	x_cord;
	int	y_cord;

	(void)param;
	(void)y;
	x_cord = -99999;
	y_cord = -99999;
	mlx_mouse_get_pos(game.mlx, game.mlx_win, &x_cord, &y_cord);
	if (game.draw.motion_x != 99999 && x_cord >= 0 && y_cord >= 0 && \
			x_cord < game.map.r_x && y_cord < game.map.r_y)
	{
		if (game.draw.motion_x > x)
			mlx_press(KEY_ARROW_LEFT);
		if (game.draw.motion_x < x)
			mlx_press(KEY_ARROW_RIGHT);
	}
	game.draw.motion_mouse = 1;
	game.draw.motion_x = x;
	return (0);
}
