/* ************************************************************************** */
/*                                                                            */
/*   parser_header.c                                                          */
/*                                                                            */
/*   Lectura linea a linea de la cabecera del archivo .cub y                 */
/*   asignacion de cada campo (NO/SO/WE/EA/F/C) al resultado.                */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"

static int	ft_parser_header_line(t_parser_result *result, const char *line)
{
	char	*content;
	int		color;

	if (ft_strncmp(line, "NO", 2) == 0)
	{
		content = ft_get_header_line_content(line, 2);
		if (!content || result->text_no_path)
			return (-1);
		result->text_no_path = content;
	}
	else if (ft_strncmp(line, "SO", 2) == 0)
	{
		content = ft_get_header_line_content(line, 2);
		if (!content || result->text_so_path)
			return (-1);
		result->text_so_path = content;
	}
	else if (ft_strncmp(line, "WE", 2) == 0)
	{
		content = ft_get_header_line_content(line, 2);
		if (!content || result->text_we_path)
			return (-1);
		result->text_we_path = content;
	}
	else if (ft_strncmp(line, "EA", 2) == 0)
	{
		content = ft_get_header_line_content(line, 2);
		if (!content || result->text_ea_path)
			return (-1);
		result->text_ea_path = content;
	}
	else if (ft_strncmp(line, "F ", 2) == 0)
	{
		content = ft_get_header_line_content(line, 1);
		if (!content || result->colorF >= 0 || !ft_check_color(content))
			return (free(content), -1);
		color = ft_rgb_to_int(content);
		free(content);
		if (color == -1)
			return (-1);
		result->colorF = color;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		content = ft_get_header_line_content(line, 1);
		if (!content || result->colorC >= 0 || !ft_check_color(content))
			return (free(content), -1);
		color = ft_rgb_to_int(content);
		free(content);
		if (color == -1)
			return (-1);
		result->colorC = color;
	}
	return (1);
}

int	ft_parser_header(t_parser_result *result, int fd)
{
	char	*line;

	result->text_no_path = NULL;
	result->text_so_path = NULL;
	result->text_ea_path = NULL;
	result->text_we_path = NULL;
	result->colorF = -1;
	result->colorC = -1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_remove_spaces(&line);
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		if (ft_parser_header_line(result, line) == -1)
		{
			free(line);
			break ;
		}
		free(line);
		line = NULL;
		if (result->text_ea_path && result->text_no_path
			&& result->text_so_path && result->text_we_path
			&& result->colorF >= 0 && result->colorC >= 0)
			return (1);
	}
	return (-1);
}
