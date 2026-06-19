/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:26:14 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 21:08:17 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_set_angle(t_parser_result *result, char angle_simbol)
{
	if (angle_simbol == 'N')
		result->s_angle = -3.14159265359 / 2;
	else if (angle_simbol == 'S')
		result->s_angle = 3.14159265359 / 2;
	else if (angle_simbol == 'W')
		result->s_angle = 3.14159265359;
	else
		result->s_angle = 0;
}

int	ft_find_spawn(char **map, int *rx, int *ry)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				*rx = x;
				*ry = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

int	ft_parser_player_spawn(t_parser_result *result)
{
	char	angle_simbol;
	int		x;
	int		y;

	if (ft_find_spawn(result->map, &x, &y) == -1)
		return (-1);
	angle_simbol = result->map[y][x];
	result->map[y][x] = '0';
	result->starting_x = (x + 0.5) * 64.0;
	result->starting_y = (y + 0.5) * 64.0;
	ft_set_angle(result, angle_simbol);
	return (1);
}

void	ft_delete_parser_result(t_parser_result *final)
{
	int	i;

	if (!final)
		return ;
	if (final->map)
	{
		i = 0;
		while (final->map[i])
			free(final->map[i++]);
		free(final->map);
	}
	free(final->text_no_path);
	free(final->text_so_path);
	free(final->text_we_path);
	free(final->text_ea_path);
	free(final);
}
