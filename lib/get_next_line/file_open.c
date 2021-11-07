/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:55:31 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/24 20:47:24 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#define PATH_LEN 70
#define D_PATH "./maps/"
#define D_EXTENSION ".cub"
#define D_ERROR "The map must end with .cub extension\n"
#define D_ERROR_LEN 37

static void	file_open_1(char *path, char *map_path)
{
	if (ft_strchr(path, '/') != NULL)
		ft_strlcpy(map_path, path, PATH_LEN);
	else
	{
		ft_strlcpy(map_path, D_PATH, PATH_LEN);
		ft_strlcat(map_path, path, PATH_LEN);
	}
}

int	file_open(char *path)
{
	char	map_path[PATH_LEN];
	int		fd;
	char	*map;
	int		map_len;

	map_len = ft_strlen(path);
	map = ft_strrchr(path, '.');
	if (map != 0 && (ft_strncmp(map, D_EXTENSION, map_len) == 0))
	{
		file_open_1(path, map_path);
		fd = open(map_path, O_RDONLY);
		if (fd < 0)
			write(1, "The map not found\n", 18);
	}
	else
	{
		write(1, D_ERROR, D_ERROR_LEN);
		return (-1);
	}
	return (fd);
}
