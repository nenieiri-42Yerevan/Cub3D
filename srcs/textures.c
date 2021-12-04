/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:04:12 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/04 18:50:47 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	textures(void)
{
	game.textures.no.img = mlx_xpm_file_to_image(game.mlx, game.map.no,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.no.addr = mlx_get_data_addr(game.textures.no.img, \
			&(game.textures.no.bits_per_pixel), \
			&(game.textures.no.line_length), &(game.textures.no.endian));
	game.textures.so.img = mlx_xpm_file_to_image(game.mlx, game.map.so,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.so.addr = mlx_get_data_addr(game.textures.so.img, \
			&(game.textures.so.bits_per_pixel), \
			&(game.textures.so.line_length), &(game.textures.so.endian));
	game.textures.we.img = mlx_xpm_file_to_image(game.mlx, game.map.we,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.we.addr = mlx_get_data_addr(game.textures.we.img, \
			&(game.textures.we.bits_per_pixel), \
			&(game.textures.we.line_length), &(game.textures.we.endian));
	game.textures.ea.img = mlx_xpm_file_to_image(game.mlx, game.map.ea,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.ea.addr = mlx_get_data_addr(game.textures.ea.img, \
			&(game.textures.ea.bits_per_pixel), \
			&(game.textures.ea.line_length), &(game.textures.ea.endian));
}
