/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:09:35 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/27 23:37:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ray_cast(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < game.map.r_x)
	{	
		y = 0;
		find_delta(x);
		find_hit();
		find_draw();
		while (y < game.map.r_y)
		{
			if (y < game.draw.draw_start)
				put_pixel(&(game.img), x, y, creat_trgb(0, game.map.cr, \
							game.map.cg, game.map.cb));
			else if (y >= game.draw.draw_start && y <= game.draw.draw_end)
			{
				int color = 0x00554711;
				if (game.pos.side == 1)
					color = color / 2;
				put_pixel(&(game.img), x, y, color);
			}
			else
				put_pixel(&(game.img), x, y, creat_trgb(0, game.map.fr, \
							game.map.fg, game.map.fb));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, 0, 0);
}

int	cub3d(void)
{
	game.map = my_map;
	game.pos = pos;
	game.draw = draw;
	game.draw.move_speed = 0.15;
	game.draw.rot_speed = 0.13;
	game.mlx = mlx_init();
	if (game.mlx == 0)
		printf("MiniLibX connection error\n");
	else
	{
		game.mlx_win = mlx_new_window(game.mlx, game.map.r_x, \
				game.map.r_y, "cub3D");
		pos_init();
		game.img.img = mlx_new_image(game.mlx, game.map.r_x, game.map.r_y);
		game.img.addr = mlx_get_data_addr(game.img.img, &(game.img.bits_per_pixel), &(game.img.line_length), &(game.img.endian));
		ray_cast();
		mlx_hook(game.mlx_win, 17, 1L << 17, mlx_close, 0);
		mlx_hook(game.mlx_win, 2, 1L << 0, mlx_press, 0);
		mlx_loop(game.mlx);
	}
	return (0);
}
