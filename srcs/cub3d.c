/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:09:35 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/20 21:08:48 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	cub3d(void)
{
	game.map = my_map;
	game.mlx = mlx_init();
	if (game.mlx == 0)
		printf("MiniLibX connection error\n");
	else
	{
		game.mlx_win = mlx_new_window(game.mlx, game.map.r_x, \
				game.map.r_y, "cub3D");
		mlx_hook(game.mlx_win, 17, 1L << 17, mlx_close, 0);
		mlx_hook(game.mlx_win, 2, 1L << 0, mlx_press, 0);
		mlx_loop(game.mlx);
	}
	return (0);
}
