/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:40:17 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/05 23:03:52 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_press(int key)
{
	if (key == KEY_ESC)
		mlx_close();
	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
		move(key);
	if (key == KEY_ARROW_LEFT || key == KEY_ARROW_RIGHT)
		rotate(key);
	return (0);
}
