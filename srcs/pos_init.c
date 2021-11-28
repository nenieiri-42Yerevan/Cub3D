/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:36:33 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/25 22:36:52 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pos_init(void)
{
	game.pos.angle = INITIAL_FOV;
	game.pos.pos_x = (float)game.pos.map_x + 0.5;
	game.pos.pos_y = (float)game.pos.map_y + 0.5;
	game.pos.dir_x = 0;
	game.pos.dir_y = 0;
	game.pos.plane_x = 0;
	game.pos.plane_y = 0;
	if (game.map.dir == 'N')
		game.pos.dir_y = -1;
	else if (game.map.dir == 'S')
		game.pos.dir_y = 1;
	else if (game.map.dir == 'W')
		game.pos.dir_x = -1;
	else if (game.map.dir == 'E')
		game.pos.dir_x = 1;
	if (game.map.dir == 'N')
		game.pos.plane_x = tan((game.pos.angle / 2) * (M_PI / 180));
	else if (game.map.dir == 'S')
		game.pos.plane_x = -tan((game.pos.angle / 2) * (M_PI / 180));
	else if (game.map.dir == 'E')
		game.pos.plane_y = tan((game.pos.angle / 2) * (M_PI / 180));
	else
		game.pos.plane_y = -tan((game.pos.angle / 2) * (M_PI / 180));
}
