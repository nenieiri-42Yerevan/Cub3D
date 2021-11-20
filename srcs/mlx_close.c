/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:07:42 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/20 19:34:48 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mlx_close(void)
{
	mlx_destroy_window(game.mlx, game.mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
