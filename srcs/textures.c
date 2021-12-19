/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:04:12 by vismaily          #+#    #+#             */
/*   Updated: 2021/12/19 17:28:10 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	tex_exist_2(int *ptr)
{
	*ptr = open(game.map.we, O_RDONLY);
	if (*ptr == -1)
	{
		errors_param(3, "WE");
		exit(0);
	}
	close(*ptr);
	*ptr = open(game.map.ea, O_RDONLY);
	if (*ptr == -1)
	{
		errors_param(3, "EA");
		exit(0);
	}
	close(*ptr);
	*ptr = open(game.map.s, O_RDONLY);
	if (*ptr == -1)
	{
		errors_param(3, "S");
		exit(0);
	}
	close(*ptr);
}

static void	tex_exist_1(void)
{
	int	ptr;

	ptr = open(game.map.no, O_RDONLY);
	if (ptr == -1)
	{
		errors_param(3, "NO");
		exit(0);
	}
	close(ptr);
	game.textures.no.img = mlx_xpm_file_to_image(game.mlx, game.map.no,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.no.addr = mlx_get_data_addr(game.textures.no.img, \
			&(game.textures.no.bits_per_pixel), \
			&(game.textures.no.line_length), &(game.textures.no.endian));
	ptr = open(game.map.so, O_RDONLY);
	if (ptr == -1)
	{
		errors_param(3, "SO");
		exit(0);
	}
	close(ptr);
	tex_exist_2(&ptr);
}

void	textures(void)
{
	tex_exist_1();
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
	game.textures.s.img = mlx_xpm_file_to_image(game.mlx, game.map.s,
			&(game.textures.tex_width), &(game.textures.tex_height));
	game.textures.s.addr = mlx_get_data_addr(game.textures.s.img, \
			&(game.textures.s.bits_per_pixel), \
			&(game.textures.s.line_length), &(game.textures.s.endian));
}
