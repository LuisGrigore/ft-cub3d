/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate_map_flood.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:07:57 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 22:34:34 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"
#include <stdio.h>
#include <stdlib.h>

static int	**ft_alloc_visited(char **map)
{
	int	**vis;
	int	y;
	int	len;

	len = 0;
	while (map[len])
		len++;
	vis = malloc(sizeof(int *) * len);
	if (!vis)
		return (NULL);
	y = 0;
	while (y < len)
	{
		vis[y] = ft_calloc(ft_strlen(map[y]) + 1, sizeof(int));
		if (!vis[y])
			return (NULL);
		y++;
	}
	return (vis);
}

static void	ft_free_visited(int **vis, char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(vis[y]);
		y++;
	}
	free(vis);
}

static int	ft_flood_fill(char **map, int y, int x, int **visited)
{
	if (ft_is_outside(map, y, x))
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1')
		return (1);
	if (visited[y][x])
		return (1);
	visited[y][x] = 1;
	if (!ft_flood_fill(map, y + 1, x, visited))
		return (0);
	if (!ft_flood_fill(map, y - 1, x, visited))
		return (0);
	if (!ft_flood_fill(map, y, x + 1, visited))
		return (0);
	if (!ft_flood_fill(map, y, x - 1, visited))
		return (0);
	return (1);
}

int	ft_check_map_closed(t_parser_result *result)
{
	char	**map;
	int		**visited;
	int		px;
	int		py;

	map = result->map;
	if (!ft_find_player(map, &py, &px))
		return (printf("Error: no player found\n"), -1);
	visited = ft_alloc_visited(map);
	if (!visited)
		return (-1);
	if (!ft_flood_fill(map, py, px, visited))
	{
		ft_free_visited(visited, map);
		return (printf("Error: Open map\n"), -1);
	}
	ft_free_visited(visited, map);
	return (1);
}
