/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_delta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:00:57 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/28 18:10:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	find_side(void)
{
	if (game.pos.ray_dir_x < 0)
	{
		game.pos.step_x = -1;
		game.pos.side_x = (game.pos.pos_x - game.pos.map_x) * game.pos.delta_x;
	}
	else
	{
		game.pos.step_x = 1;
		game.pos.side_x = (game.pos.map_x + 1 - game.pos.pos_x) * \
			game.pos.delta_x;
	}
	if (game.pos.ray_dir_y < 0)
	{
		game.pos.step_y = -1;
		game.pos.side_y = (game.pos.pos_y - game.pos.map_y) * \
			game.pos.delta_y;
	}
	else
	{
		game.pos.step_y = 1;
		game.pos.side_y = (game.pos.map_y + 1 - game.pos.pos_y) * \
			game.pos.delta_y;
	}
}

void	find_delta(int x)
{
	game.pos.camera = 2 * x / (float)game.map.r_x - 1;
	game.pos.ray_dir_x = game.pos.dir_x + game.pos.plane_x * game.pos.camera;
	game.pos.ray_dir_y = game.pos.dir_y + game.pos.plane_y * game.pos.camera;
	game.pos.map_x = (int)game.pos.pos_x;
	game.pos.map_y = (int)game.pos.pos_y;
	game.pos.ray_dir = sqrt(game.pos.ray_dir_x * game.pos.ray_dir_x + \
			game.pos.ray_dir_y * game.pos.ray_dir_y);
	if (game.pos.ray_dir_x == 0)
		game.pos.delta_x = 10000000;
	else
		game.pos.delta_x = fabs(game.pos.ray_dir / game.pos.ray_dir_x);
	if (game.pos.ray_dir_y == 0)
		game.pos.delta_y = 10000000;
	else
		game.pos.delta_y = fabs(game.pos.ray_dir / game.pos.ray_dir_y);
	find_side();
}
