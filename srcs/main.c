/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:12:51 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/20 21:09:53 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	size_t	map_height;

	if (argc == 2)
	{
		fd = file_open(argv[1]);
		if (fd > 0)
		{
			map_height = read_map_2d(fd, &map);
			if (map_height == (size_t)(-1))
			{
				printf("Map is empty :(\n");
				return (0);
			}
			if (parsing_map(&map, map_height) == 0)
				cub3d();
		}
		else
			printf("File open error\n");
	}
	else
		printf("You must give 1 argument to your program,"
			" and that have to be a map with .cub extension\n");
	return (0);
}
