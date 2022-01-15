/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:09:09 by vismaily          #+#    #+#             */
/*   Updated: 2022/01/15 23:19:03 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ray_cast(void)
{
	int	x;
	int	y;

	move();
	rotate();
	draw_floor();
	x = 0;
	while (x < game.map.r_x)
	{	
		y = 0;
		find_delta(x);
		find_hit();
		find_draw();
		while (y < game.map.r_y)
			draw(&x, &y);
		game.sprites.perp_dists[x] = game.draw.wall_dist;
		x++;
	}
	draw_sprites();
	mlx_do_sync(game.mlx);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
	return (0);
}
