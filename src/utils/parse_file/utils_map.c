/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:14:40 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/26 15:38:07 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parseo.h"

int	ft_is_valid(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\t');
}

int	ft_check_each_space(char **map, int y, int x)
{
	if (y == 0)
	{
		while (map[y][x] == ' ')
			y++;
	}
	else
	{
		while (map[y][x] == ' ')
			y--;
	}
	if (map[y][x] == '1')
		return (1);
	return (0);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int	ft_check_inside(char **map, int y, int x)
{
	while (x >= 0)
	{
		if(x != 0 && map[y][x] == '0')
		{
			if (map[y][x - 1] == ' ' || map[y][x + 1] == ' ')
				return (0);
			if (map[y - 1][x] == ' ' || map[y + 1][x] == ' ')
				return (0);
		}
		x--;
	}
	return (1);
}

t_map *ft_create_grid(t_map *map)
{
	t_map	*grid;
	int		i;
	
	grid = (t_map *) malloc(sizeof(t_map));
	if(!grid)
		return (NULL);
	grid->map = (char **) malloc(sizeof(char *) * (map->height + 1));
	i = 0;
	while (map->map[i])
	{
		grid->map[i] = ft_strdup(map->map[i]);
		i++;
	}
	grid->map[i] = NULL;
	grid->height = map->height;
	grid->len_max= map->len_max;
	return (grid);
}
