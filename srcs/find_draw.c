/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:58:38 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/28 17:21:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_draw(void)
{
	game.draw.line_height = (int)round(game.map.r_y / game.draw.wall_dist);
	game.draw.draw_start = game.map.r_y / 2 - game.draw.line_height / 2;
	if (game.draw.draw_start < 0)
		game.draw.draw_start = 0;
	game.draw.draw_end = game.map.r_y / 2 + game.draw.line_height / 2;
	if (game.draw.draw_end >= game.map.r_y)
		game.draw.draw_end = game.map.r_y - 1;
}
