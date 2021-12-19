/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:40:17 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/19 17:30:20 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_press(int key)
{
	if (key == KEY_ESC)
		mlx_close();
	if (key == KEY_ARROW_LEFT)
		game.keys.left = 1;
	if (key == KEY_ARROW_RIGHT)
		game.keys.right = 1;
	if (key == KEY_W)
		game.keys.w = 1;
	if (key == KEY_S)
		game.keys.s = 1;
	if (key == KEY_A)
		game.keys.a = 1;
	if (key == KEY_D)
		game.keys.d = 1;
	return (0);
}

int	mlx_release(int key)
{
	if (key == KEY_ARROW_LEFT)
		game.keys.left = 0;
	if (key == KEY_ARROW_RIGHT)
		game.keys.right = 0;
	if (key == KEY_W)
		game.keys.w = 0;
	if (key == KEY_S)
		game.keys.s = 0;
	if (key == KEY_A)
		game.keys.a = 0;
	if (key == KEY_D)
		game.keys.d = 0;
	return (0);
}
