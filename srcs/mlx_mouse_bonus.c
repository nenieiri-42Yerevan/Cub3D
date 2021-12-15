/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:36:48 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/16 00:40:58 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_mouse(int key)
{
	if (game.draw.motion_x != 9999)
	{
		if (game.draw.motion_x > key)
			mlx_press(KEY_ARROW_LEFT);
		if (game.draw.motion_x < key)
			mlx_press(KEY_ARROW_RIGHT);
	}
	game.draw.motion_mouse = 1;
	game.draw.motion_x = key;
	return (0);
}
