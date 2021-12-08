/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:09:35 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/05 22:53:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	game_init(void)
{
	game.map = my_map;
	game.draw.move_speed = 0.15;
	game.draw.rot_speed = 0.12;
	game.textures.tex_width = 64;
	game.textures.tex_height = 64;
}

int	cub3d(void)
{
	game_init();
	game.mlx = mlx_init();
	if (game.mlx == 0)
		printf("MiniLibX connection error\n");
	else
	{
		game.mlx_win = mlx_new_window(game.mlx, game.map.r_x, \
				game.map.r_y, "cub3D");
		textures();
		pos_init();
		game.img.img = mlx_new_image(game.mlx, game.map.r_x, game.map.r_y);
		game.img.addr = mlx_get_data_addr(game.img.img, \
				&(game.img.bits_per_pixel), &(game.img.line_length), \
				&(game.img.endian));
		ray_cast();
		mlx_hook(game.mlx_win, 17, 1L << 17, mlx_close, 0);
		mlx_hook(game.mlx_win, 2, 1L << 0, mlx_press, 0);
		mlx_loop_hook(game.mlx, ray_cast, NULL);
		mlx_loop(game.mlx);
	}
	return (0);
}
