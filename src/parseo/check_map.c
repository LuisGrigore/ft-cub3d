/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 23:34:22 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/26 14:23:01 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"


static int	ft_check_top_bottom(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x])
	{
		if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '\t')
			return (0);
		if (!ft_check_each_space(map, y, x))
			return (0);
		x++;
	}
	return (1);
}

static int	ft_check_sides(char **map, int height)
{
	int	i;
	int	j;

	if (!ft_check_top_bottom(map, 0))
		return (printf("Error: fila superior abierta\n"), 0);
	i = 1;
	while (i < height - 1)
	{
		j = ft_strlen(map[i]) - 1;
		while (j > 0 && (map[i][j] == ' ' || map[i][j] == '\t'))
			j--;
		if (map[i][j] != '1')
			return (printf("Error: fila %d abierta por la derecha\n", i), 0);
		if (!ft_check_inside(map, i, j))
			return (printf("Error: fila %d abierta por dentro\n", i), 0);
		i++;
	}
	if (!ft_check_top_bottom(map, height - 1))
		return (printf("Error: fila inferior abierta\n"), 0);
	return (1);
}

static int	ft_check_player_pos(char **map, int height, int px, int py)
{
	if (py <= 0 || py >= height - 1)
		return (printf("Error: jugador en el borde\n"), 0);
	if (ft_is_space(map[py][px - 1]) || ft_is_space(map[py][px + 1]))
		return (printf("Error: jugador expuesto horizontalmente\n"), 0);
	if (!map[py - 1] || ft_strlen(map[py - 1]) <= (size_t)px
		|| ft_is_space(map[py - 1][px]))
		return (printf("Error: jugador expuesto arriba\n"), 0);
	if (!map[py + 1] || ft_strlen(map[py + 1]) <= (size_t)px
		|| ft_is_space(map[py + 1][px]))
		return (printf("Error: jugador expuesto abajo\n"), 0);
	return (1);
}

static int	ft_val_char_player(char **map, int *px, int *py)
{
	int	pos[2];
	int	player;

	player = 0;
	pos[0] = 0;
	while (map[pos[0]])
	{
		pos[1] = 0;
		while (map[pos[0]][pos[1]])
		{
			if (!ft_is_valid(map[pos[0]][pos[1]]))
				return (printf("Error: caracter invalido '%c'\n", map[pos[0]][pos[1]]), 0);
			if (ft_strchr("NSEW", map[pos[0]][pos[1]]))
			{
				player++;
				*px = pos[1];
				*py = pos[0];
			}
			pos[1]++;
		}
		pos[0]++;
	}
	if (player != 1)
		return (printf("Error: numero de jugadores invalido\n"), 0);
	return (1);
}

int	ft_val_map(char **map, int height, int width)
{
	int	px;
	int	py;

	(void)width;
	if (!ft_val_char_player(map, &px, &py))
		return (0);
	if (!ft_check_sides(map, height))
		return (0);
	if (!ft_check_player_pos(map, height, px, py))
		return (0);
	return (1);
}
