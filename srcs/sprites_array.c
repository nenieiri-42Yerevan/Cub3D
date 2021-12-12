/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:24:17 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/12 15:36:09 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	sprites_set(void)
{
	size_t	i;
	size_t	j;
	size_t	len;
	int		count;

	i = -1;
	count = 0;
	while (++i < game.map.map_height)
	{
		j = -1;
		len = ft_strlen(game.map.map[i]);
		while (++j < len)
		{
			if (game.map.map[i][j] == '2')
			{
				game.sprites.sprites[count].x = j + 0.5;
				game.sprites.sprites[count].y = i + 0.5;
				game.sprites.sprites[count].texture = game.map.map[i][j];
				count++;
			}
		}
	}
}

void	sprites_array(void)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = -1;
	game.sprites.count = 0;
	while (++i < game.map.map_height)
	{
		j = -1;
		len = ft_strlen(game.map.map[i]);
		while (++j < len)
			if (game.map.map[i][j] == '2')
				(game.sprites.count)++;
	}
	if (game.sprites.count != 0)
	{
		game.sprites.sprites = ft_calloc(game.sprites.count, sizeof(t_sprite));
		if (game.sprites.sprites == 0)
			exit(EXIT_FAILURE);
		else
			sprites_set();
	}
}
