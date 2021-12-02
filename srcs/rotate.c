/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 01:19:54 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/03 01:42:41 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_right(double old_dir_x, double old_plane_x)
{
	game.pos.dir_x = game.pos.dir_y * sin(-game.draw.rot_speed) + \
					game.pos.dir_x * cos(-game.draw.rot_speed);
	game.pos.dir_y = game.pos.dir_y * cos(-game.draw.rot_speed) - \
					old_dir_x * sin(-game.draw.rot_speed);
	game.pos.plane_x = game.pos.plane_y * sin(-game.draw.rot_speed) + \
					game.pos.plane_x * cos(-game.draw.rot_speed);
	game.pos.plane_y = game.pos.plane_y * cos(-game.draw.rot_speed) - \
					old_plane_x * sin(-game.draw.rot_speed);
}

void	rotate(int key)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game.pos.dir_x;
	old_plane_x = game.pos.plane_x;
	if (key == KEY_ARROW_LEFT)
	{
		game.pos.dir_x = game.pos.dir_y * sin(game.draw.rot_speed) + \
					game.pos.dir_x * cos(game.draw.rot_speed);
		game.pos.dir_y = game.pos.dir_y * cos(game.draw.rot_speed) - \
					old_dir_x * sin(game.draw.rot_speed);
		game.pos.plane_x = game.pos.plane_y * sin(game.draw.rot_speed) + \
					game.pos.plane_x * cos(game.draw.rot_speed);
		game.pos.plane_y = game.pos.plane_y * cos(game.draw.rot_speed) - \
					old_plane_x * sin(game.draw.rot_speed);
	}
	else if (key == KEY_ARROW_RIGHT)
		rotate_right(old_dir_x, old_plane_x);
	ray_cast();
}
