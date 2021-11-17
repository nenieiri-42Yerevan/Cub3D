/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:08:24 by vismaily          #+#    #+#             */
/*   Updated: 2021/11/13 20:51:08 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	errors_two(int n)
{
	if (n == 8)
		printf("Error:The map must be contain only one N, S, E or W character");
	else if (n == 9)
		printf("Error:The map must be contain N, S, E or W character");
	else if (n == 10)
		printf("Error:There are duplicates in your map");
	return (1);
}

int	errors(int n)
{
	if (n == 1)
		printf("Error in x size of resolution\n");
	else if (n == 2)
		printf("Error in y size of resolution\n");
	else if (n == 3)
		printf("Error in resolution\n");
	else if (n == 4)
		printf("Error\nX resolution must be from 640 to 4096\n"
			"Y resolution must be from 480 to 2160\n");
	else if (n == 5)
		printf("Error: Map can't have empty lines");
	else if (n == 6)
		printf("Error: The map must be closed/surrounded by walls");
	else if (n == 7)
		printf("Error: The map must be composed only of only 4 possible:"
			"characters\n0 - for an empty space\n1 - for a wall\n"
			"2 - for an item\nN, S, E or W - for the player's start"
			"position and spawning orientation");
	else
		return (errors_two(n));
	return (1);
}

int	errors_param(int n, char *str)
{
	if (n == 1)
		printf("Error in path of \"%s\"\n", str);
	if (n == 2)
		printf("Error in color line \"%s\"\n", str);
	return (1);
}

int	errors_settings(int n)
{	
	if (n == 1)
		printf("Resolution does not found or it must be placed in"
			" the top of map\n");
	else if (n == 2)
		printf("NO does not found or it must be placed in the top of map\n");
	else if (n == 3)
		printf("SO does not found or it must be placed in the top of map\n");
	else if (n == 4)
		printf("WE does not found or it must be placed in the top of map\n");
	else if (n == 5)
		printf("EA does not found or it must be placed in the top of map\n");
	else if (n == 6)
		printf("S does not found or it must be placed in the top of map\n");
	else if (n == 7)
		printf("F does not found or it must be placed in the top of map "
			"or F must be in range [0, 255]\n");
	else if (n == 8)
		printf("C does not found or it must be placed in the top of map "
			"or C must be in range [0, 255]\n");
	return (1);
}
