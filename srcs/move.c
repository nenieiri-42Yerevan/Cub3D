/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:58:01 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/12 22:48:13 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_left_right(void)
{
	if (game.keys.a == 1)
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
	if (game.keys.d == 1)
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

static void	move_down(void)
{
	if (game.keys.s == 1)
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
	move_left_right();
}

void	move(void)
{
	if (game.keys.w == 1)
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
	move_down();
}
