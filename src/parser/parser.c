/* ************************************************************************** */
/*                                                                            */
/*   parser.c                                                                 */
/*                                                                            */
/*   Punto de entrada del parser: orquesta cabecera + mapa + validaciones,   */
/*   extrae el spawn del jugador y libera el resultado.                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_parser_player_spawn(t_parser_result *result)
{
	int		x;
	int		y;
	char	angle_simbol;
	char	**map;

	map = result->map;
	angle_simbol = '\0';
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				angle_simbol = map[y][x];
				map[y][x] = '0';
				result->starting_x = (x + 0.5) * 64.0;
				result->starting_y = (y + 0.5) * 64.0;;
				if (angle_simbol == 'N')
					result->starting_angle = -3.14159265359 / 2;
				else if (angle_simbol == 'S')
					result->starting_angle = 3.14159265359 / 2;
				else if (angle_simbol == 'W')
					result->starting_angle = 3.14159265359;
				else
					result->starting_angle = 0;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (-1);
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

t_parser_result	*ft_parser(char *path)
{
	t_parser_result	*result;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = malloc(sizeof(t_parser_result));
	if (!result)
		return (close(fd), NULL);
	result->map = NULL;
	if (ft_parser_header(result, fd) == -1)
	{
		printf("Error parsing header\n");
		return (close(fd), ft_delete_parser_result(result), NULL);
	}
	if (ft_check_header(result) == -1)
	{
		printf("Error: invalid header\n");
		return (close(fd), ft_delete_parser_result(result), NULL);
	}
	if (ft_parser_map(result, fd) == -1)
	{
		printf("Error parsing map\n");
		return (close(fd), ft_delete_parser_result(result), NULL);
	}
	close(fd);
	if (ft_validate_map_chars(result) == -1)
	{
		printf("Error: invalid char in map\n");
		return (ft_delete_parser_result(result), NULL);
	}
	if (ft_check_map_closed(result) == -1)
	{
		printf("Error: map not closed\n");
		return (ft_delete_parser_result(result), NULL);
	}
	if (ft_parser_player_spawn(result) == -1)
	{
		printf("Error parsing player\n");
		return (ft_delete_parser_result(result), NULL);
	}
	return (result);
}
