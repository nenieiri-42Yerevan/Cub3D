/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:54:14 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/28 18:08:40 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	void	find_wall_dist(void)
{
	if (game.pos.side == 0)
		game.draw.wall_dist = game.pos.side_x - game.pos.delta_x;
	else
		game.draw.wall_dist = game.pos.side_y - game.pos.delta_y;
	game.draw.wall_dist /= game.pos.ray_dir;
}

void	find_hit(void)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game.pos.side_x < game.pos.side_y)
		{
			game.pos.map_x += game.pos.step_x;
			game.pos.side = 0;
			game.pos.side_x += game.pos.delta_x;
		}
		else
		{
			game.pos.map_y += game.pos.step_y;
			game.pos.side = 1;
			game.pos.side_y += game.pos.delta_y;
		}
		if (game.map.map[game.pos.map_y][game.pos.map_x] == '1')
			hit = 1;
	}
	find_wall_dist();
}
