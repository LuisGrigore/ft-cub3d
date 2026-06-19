/* ************************************************************************** */
/*                                                                            */
/*   parser_validate_map.c                                                    */
/*                                                                            */
/*   Validacion del mapa:                                                     */
/*   - Caracteres permitidos                                                  */
/*   - Un solo jugador                                                        */
/*   - Mapa cerrado usando flood fill                                         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/parser_internal.h"
#include "../../externals/libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

/* ========================= VALIDAR CARACTERES ========================= */

int	ft_validate_map_chars(t_parser_result *result)
{
	int		x;
	int		y;
	char	**map;
	char	c;
	int		n_players;

	n_players = 0;
	map = result->map;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			c = map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				n_players++;
			if (n_players > 1 || !(c == '0' || c == '1'
					|| c == 'N' || c == 'S'
					|| c == 'E' || c == 'W'
					|| c == ' ' || c == '\t'))
				return (-1);
			x++;
		}
		y++;
	}
	if (n_players != 1)
		return (-1);
	return (1);
}

/* ========================= UTILS ========================= */

static int	ft_last_valid_index(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
		i--;
	return (i);
}

static int	ft_is_outside(char **map, int y, int x)
{
	int	last;

	if (y < 0 || !map[y])
		return (1);
	last = ft_last_valid_index(map[y]);
	if (x < 0 || x > last)
		return (1);
	return (0);
}

/* ========================= BUSCAR JUGADOR ========================= */

static int	ft_find_player(char **map, int *py, int *px)
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

/* ========================= VISITED ========================= */

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

/* ========================= FLOOD FILL ========================= */

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

/* ========================= MAP CLOSED ========================= */

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
		return (printf("Error: mapa abierto\n"), -1);
	}

	ft_free_visited(visited, map);
	return (1);
}