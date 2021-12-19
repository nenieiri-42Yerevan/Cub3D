/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 15:07:48 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/19 17:27:45 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	floor_texture(void)
{
	int	ptr;

	ptr = open(FLOOR, O_RDONLY);
	if (ptr == -1)
	{
		errors_param(3, "FLOOR");
		exit(0);
	}
	close(ptr);
	game.textures.floor.img = mlx_xpm_file_to_image(game.mlx, FLOOR,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.floor.addr = mlx_get_data_addr(game.textures.floor.img, \
			&(game.textures.floor.bits_per_pixel), \
			&(game.textures.floor.line_length), &(game.textures.floor.endian));
}

static void	draw_line(float floor_x, float floor_y, float step_x, float step_y)
{
	int			x;
	int			tex_x;
	int			tex_y;
	int			color;

	x = -1;
	while (++x < game.map.r_x)
	{
		tex_x = (int)(game.textures.tex_width * (floor_x - (int)floor_x));
		tex_y = (int)(game.textures.tex_height * (floor_y - (int)floor_y));
		floor_x += step_x;
		floor_y += step_y;
		color = get_color(&game.textures.floor, abs(tex_x), abs(tex_y));
		put_pixel(&(game.img), x, game.draw.draw_floor_y, color);
	}
}

void	draw_floor(void)
{
	int		y;
	float	step_x;
	float	step_y;
	float	floor_x;
	float	floor_y;

	floor_texture();
	y = game.map.r_y / 2 - 1;
	while (++y < game.map.r_y)
	{
		game.draw.draw_floor_y = y;
		game.draw.floor_row_dist = (game.map.r_y * 0.5) / \
			(y - game.map.r_y * 0.5);
		step_x = game.draw.floor_row_dist * (2 * game.pos.plane_x) / \
			game.map.r_x;
		step_y = game.draw.floor_row_dist * (2 * game.pos.plane_y) / \
			game.map.r_x;
		floor_x = game.pos.pos_x + game.draw.floor_row_dist * \
			(game.pos.dir_x - game.pos.plane_x);
		floor_y = game.pos.pos_y + game.draw.floor_row_dist * \
			(game.pos.dir_y - game.pos.plane_y);
		draw_line(floor_x, floor_y, step_x, step_y);
	}
}
