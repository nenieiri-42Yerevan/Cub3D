/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:09:35 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/12 23:35:11 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	game_init(void)
{
	game.map = my_map;
	game.draw.move_speed = 0.09;
	game.draw.rot_speed = 0.05;
	game.sprites.perp_dists = ft_calloc(game.map.r_x, sizeof(double));
	if (game.sprites.perp_dists == 0)
	{
		printf("Memory allocation error (for dists' list)\n");
		exit(EXIT_FAILURE);
	}
	game.textures.tex_width = 64;
	game.textures.tex_height = 64;
	game.keys.a = 0;
	game.keys.s = 0;
	game.keys.d = 0;
	game.keys.w = 0;
	game.keys.left = 0;
	game.keys.right = 0;
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
		sprites_array();
		textures();
		pos_init();
		game.img.img = mlx_new_image(game.mlx, game.map.r_x, game.map.r_y);
		game.img.addr = mlx_get_data_addr(game.img.img, \
				&(game.img.bits_per_pixel), &(game.img.line_length), \
				&(game.img.endian));
		ray_cast();
		mlx_hook(game.mlx_win, 17, 1L << 17, mlx_close, 0);
		mlx_hook(game.mlx_win, 2, 1L << 0, mlx_press, 0);
		mlx_hook(game.mlx_win, 3, 1L << 1, mlx_release, 0);
		mlx_loop_hook(game.mlx, ray_cast, NULL);
		mlx_loop(game.mlx);
	}
	return (0);
}
