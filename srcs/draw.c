/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:03:13 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/19 15:02:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw(int *x, int *y)
{
	int	color;

	if (*y < game.draw.draw_start)
		put_pixel(&(game.img), *x, *y, creat_trgb(0, game.map.cr, \
					game.map.cg, game.map.cb));
	else if (*y >= game.draw.draw_start && *y < game.draw.draw_end)
	{
		game.draw.tex_y = (int)game.draw.tex_pos;
		game.draw.tex_pos += game.draw.step;
		color = get_color(&game.draw.tex, game.draw.tex_x, game.draw.tex_y);
		put_pixel(&(game.img), *x, *y, color);
	}
	else
		if (BONUS == 0)
			put_pixel(&(game.img), *x, *y, creat_trgb(0, game.map.fr, \
					game.map.fg, game.map.fb));
	(*y)++;
}
