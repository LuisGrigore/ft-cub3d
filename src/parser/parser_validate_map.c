/* ************************************************************************** */
/*                                                                            */
/*   parser_validate_map.c                                                    */
/*                                                                            */
/*   Validacion del mapa ya normalizado: caracteres permitidos, un solo      */
/*   jugador y mapa completamente cerrado por paredes ('1').                 */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"
#include <stdio.h>

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
			if (n_players > 1 || !(c == '0' || c == '1' || c == 'N'
				|| c == 'S' || c == 'E' || c == 'W'
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

int	ft_check_each_space(char **map, int y, int x)
{
	if (y == 0)
	{
		while (map[y] && map[y][x] == ' ')
			y++;
	}
	else
	{
		while (y > 0 && map[y][x] == ' ')
			y--;
	}
	if (!map[y] || map[y][x] != '1')
		return (0);
	return (1);
}

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

int	ft_check_inside(char **map, int y, int x)
{
	while (x >= 0)
	{
		if (x != 0 && ft_strchr("0NSEW", map[y][x]))  // ← era solo '0'
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

int	ft_check_map_closed(t_parser_result *result)
{
	int		i;
	int		j;
	char	**map;

	map = result->map;
	if (!ft_check_top_bottom(map, 0))
		return (printf("Error: fila superior abierta\n"), -1);
	i = 1;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (j > 0 && (map[i][j] == ' ' || map[i][j] == '\t'))
			j--;
		if (map[i][j] != '1')
			return (printf("Error: fila %d abierta por la derecha\n", i), -1);
		if (!ft_check_inside(map, i, j))
			return (printf("Error: fila %d abierta por dentro\n", i), -1);
		i++;
	}
	if (!ft_check_top_bottom(map, i - 1))
		return (printf("Error: fila inferior abierta\n"), -1);
	return (1);
}
