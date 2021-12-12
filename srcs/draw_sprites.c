/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:48:00 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/12 20:35:09 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sprites_init(int i)
{
	double	sprite_x;
	double	sprite_y;
	double	invDet;

	sprite_x = game.sprites.sprites[i].x - game.pos.pos_x;
	sprite_y = game.sprites.sprites[i].y - game.pos.pos_y;
	
	invDet = 1.0 / (game.pos.plane_x * game.pos.dir_y - \
			game.pos.dir_x * game.pos.plane_y);
	game.sprites.sprites[i].transform_x = invDet * \
					(game.pos.dir_y * sprite_x - game.pos.dir_x * sprite_y);
	game.sprites.sprites[i].transform_y = invDet * \
				  (-game.pos.plane_y * sprite_x + game.pos.plane_x * sprite_y);
	game.sprites.sprites[i].sprite_screen_x = (int)(game.map.r_x / 2) * \
			(1 + game.sprites.sprites[i].transform_x / \
			game.sprites.sprites[i].transform_y);
}

static void	find_draw_sprites(int i)
{
	game.sprites.sprites[i].sprite_height = abs((int)(game.map.r_y / \
			game.sprites.sprites[i].transform_y));
	game.sprites.sprites[i].draw_start_y = game.map.r_y / 2 - \
			game.sprites.sprites[i].sprite_height / 2;
	if (game.sprites.sprites[i].draw_start_y < 0)
		game.sprites.sprites[i].draw_start_y = 0;
	game.sprites.sprites[i].draw_end_y = game.map.r_y / 2 + \
			game.sprites.sprites[i].sprite_height / 2;
	if (game.sprites.sprites[i].draw_end_y >= game.map.r_y)
		game.sprites.sprites[i].draw_end_y = game.map.r_y - 1;
	game.sprites.sprites[i].sprite_width = abs((int)(game.map.r_y / \
			game.sprites.sprites[i].transform_y));
	game.sprites.sprites[i].draw_start_x = \
			game.sprites.sprites[i].sprite_screen_x - \
			game.sprites.sprites[i].sprite_width / 2;
	if (game.sprites.sprites[i].draw_start_x < 0)
		game.sprites.sprites[i].draw_start_x = 0;
	game.sprites.sprites[i].draw_end_x = \
			game.sprites.sprites[i].sprite_screen_x + \
			game.sprites.sprites[i].sprite_width / 2;
	if (game.sprites.sprites[i].draw_end_x >= game.map.r_x)
		game.sprites.sprites[i].draw_end_x = game.map.r_x - 1;
}

static void	draw_sprites_on_screen(int i)
{
	int	stripe;
	int	y;
	int	tex_x;
	int	tex_y;
	int	d;
	int	color;

	stripe = game.sprites.sprites[i].draw_start_x - 1;
	while (++stripe < game.sprites.sprites[i].draw_end_x)
	{
		y = game.sprites.sprites[i].draw_start_y - 1;
		tex_x = (int)((stripe - (game.sprites.sprites[i].sprite_screen_x - \
				game.sprites.sprites[i].sprite_width / 2)) * \
				game.textures.tex_width / game.sprites.sprites[i].sprite_width);
		if (stripe > 0 && stripe < game.map.r_x)
		{
			if (game.sprites.sprites[i].transform_y > 0 && \
				game.sprites.sprites[i].transform_y < \
				game.sprites.perp_dists[stripe])
			{
				while (++y < game.sprites.sprites[i].draw_end_y)
				{
					d = y - game.map.r_y / 2 + game.sprites.sprites[i].sprite_height / 2;
					tex_y = d * game.textures.tex_height / game.sprites.sprites[i].sprite_height;
					if (game.sprites.sprites[i].texture == '2')
					{
						color = get_color(&game.textures.s, tex_x, tex_y);
						if ((color & 0xFF000000) != 0xFF000000)
							put_pixel(&(game.img), stripe, y, color);
					}
				}
			}
		}
	}
}

void	draw_sprites(void)
{
	int	i;

	i = -1;
	sprites_sort();
	while (++i < game.sprites.count)
	{
		sprites_init(i);
		find_draw_sprites(i);
		draw_sprites_on_screen(i);
	}
}
