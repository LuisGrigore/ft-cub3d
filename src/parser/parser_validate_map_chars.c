/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate_map_chars.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:07:57 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 20:15:11 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_is_valid_char(char c, int *n_players)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		(*n_players)++;
	if (*n_players > 1)
		return (0);
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_validate_map_chars(t_parser_result *result)
{
	int		x;
	int		y;
	char	**map;
	int		n_players;

	n_players = 0;
	map = result->map;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (!ft_is_valid_char(map[y][x], &n_players))
				return (-1);
			x++;
		}
		y++;
	}
	if (n_players != 1)
		return (-1);
	return (1);
}

int	ft_last_valid_index(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
		i--;
	return (i);
}

int	ft_is_outside(char **map, int y, int x)
{
	int	last;

	if (y < 0 || !map[y])
		return (1);
	last = ft_last_valid_index(map[y]);
	if (x < 0 || x > last)
		return (1);
	return (0);
}

int	ft_find_player(char **map, int *py, int *px)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				*py = y;
				*px = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
