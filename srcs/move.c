/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:58:01 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/01 00:47:19 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_left_right(int key)
{
	if (key == KEY_A)
	{
		if (ft_strchr(NO_WALL, \
					game.map.map[(int)game.pos.pos_y][(int)(game.pos.pos_x - \
						game.pos.plane_x * game.draw.move_speed)]) != NULL)
			game.pos.pos_x -= game.pos.plane_x * game.draw.move_speed;
		if (ft_strchr(NO_WALL, game.map.map[(int)(game.pos.pos_y - \
						game.pos.plane_y * \
						game.draw.move_speed)][(int)game.pos.pos_x]) != NULL)
			game.pos.pos_y -= game.pos.plane_y * game.draw.move_speed;
	}
	else if (key == KEY_D)
	{
		if (ft_strchr(NO_WALL, \
					game.map.map[(int)game.pos.pos_y][(int)(game.pos.pos_x + \
						game.pos.plane_x * game.draw.move_speed)]) != NULL)
			game.pos.pos_x += game.pos.plane_x * game.draw.move_speed;
		if (ft_strchr(NO_WALL, game.map.map[(int)(game.pos.pos_y + \
						game.pos.plane_y * \
						game.draw.move_speed)][(int)game.pos.pos_x]) != NULL)
			game.pos.pos_y += game.pos.plane_y * game.draw.move_speed;
	}
}

void	move(int key)
{
	if (key == KEY_W)
	{
		if (ft_strchr(NO_WALL, game.map.map[(int)(game.pos.pos_y + \
						game.pos.dir_y * \
						game.draw.move_speed)][(int)game.pos.pos_x]) != NULL)
			game.pos.pos_y += game.pos.dir_y * game.draw.move_speed;
		if (ft_strchr(NO_WALL, \
					game.map.map[(int)game.pos.pos_y][(int)(game.pos.pos_x + \
						game.pos.dir_x * game.draw.move_speed)]) != NULL)
			game.pos.pos_x += game.pos.dir_x * game.draw.move_speed;
	}
	else if (key == KEY_S)
	{
		if (ft_strchr(NO_WALL, game.map.map[(int)(game.pos.pos_y - \
						game.pos.dir_y * \
						game.draw.move_speed)][(int)game.pos.pos_x]) != NULL)
			game.pos.pos_y -= game.pos.dir_y * game.draw.move_speed;
		if (ft_strchr(NO_WALL, \
					game.map.map[(int)game.pos.pos_y][(int)(game.pos.pos_x - \
						game.pos.dir_x * game.draw.move_speed)]) != NULL)
			game.pos.pos_x -= game.pos.dir_x * game.draw.move_speed;
	}
	else
		move_left_right(key);
}
