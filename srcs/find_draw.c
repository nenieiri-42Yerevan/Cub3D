/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:58:38 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/19 14:05:20 by vismaily         ###   ########.fr       */
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
		game.draw.draw_end = game.map.r_y;
	game.draw.tex_x = (int)(game.draw.hit_point * game.textures.tex_width);
	game.draw.step = (double)game.textures.tex_height / \
					(double)game.draw.line_height;
	if (game.pos.side == 0 && game.pos.ray_dir_x < 0)
		game.draw.tex = game.textures.we;
	else if (game.pos.side == 0 && game.pos.ray_dir_x > 0)
		game.draw.tex = game.textures.ea;
	else if (game.pos.side == 1 && game.pos.ray_dir_y < 0)
		game.draw.tex = game.textures.no;
	else if (game.pos.side == 1 && game.pos.ray_dir_y > 0)
		game.draw.tex = game.textures.so;
	game.draw.tex_pos = game.draw.step * (int)(game.draw.draw_start - \
			game.map.r_y / 2 + game.draw.line_height / 2);
}
