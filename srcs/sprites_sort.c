/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:34:58 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/11 14:31:38 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sprites_set_dist(void)
{
	int	i;

	i = -1;
	while (++i < game.sprites.count)
	{
		game.sprites.sprites[i].dist = \
				(game.pos.pos_x - game.sprites.sprites[i].x) * \
				(game.pos.pos_x - game.sprites.sprites[i].x) + \
				(game.pos.pos_y - game.sprites.sprites[i].y) * \
				(game.pos.pos_y - game.sprites.sprites[i].y);
	}
}

void	sprites_sort(void)
{
	int			i;
	int			j;
	int			min_idx;
	t_sprite	tmp;

	sprites_set_dist();
	i = -1;
	while (++i < game.sprites.count - 1)
	{
		min_idx = i;
		j = i + 1;
		while (++j < game.sprites.count)
			if (game.sprites.sprites[j].dist > \
					game.sprites.sprites[min_idx].dist)
				min_idx = j;
		tmp = game.sprites.sprites[i];
		game.sprites.sprites[i] = game.sprites.sprites[min_idx];
		game.sprites.sprites[min_idx] = tmp;
	}
}
