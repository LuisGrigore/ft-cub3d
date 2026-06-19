/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:15:40 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 21:25:04 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_parse_texture(char **dst, const char *line, int offset)
{
	char	*content;

	content = ft_get_header_line_content(line, offset);
	if (!content || *dst)
	{
		printf("Error texture already set.");
		return (-1);
	}
	*dst = content;
	return (1);
}

int	ft_parse_color(int *dst, const char *line)
{
	char	*content;
	int		color;

	content = ft_get_header_line_content(line, 1);
	if (!content || *dst >= 0 || !ft_check_color(content))
	{
		printf("Error, can`t set this color.(Color may already be set)");
		return (free(content), -1);
	}
	color = ft_rgb_to_int(content);
	free(content);
	if (color == -1)
		return (-1);
	*dst = color;
	return (1);
}

int	ft_parse_texture_line(t_parser_result *result, const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (ft_parse_texture(&result->text_no_path, line, 2));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (ft_parse_texture(&result->text_so_path, line, 2));
	if (ft_strncmp(line, "WE", 2) == 0)
		return (ft_parse_texture(&result->text_we_path, line, 2));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (ft_parse_texture(&result->text_ea_path, line, 2));
	return (1);
}

int	ft_parser_header_line(t_parser_result *result, const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		return (ft_parse_texture_line(result, line));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (ft_parse_color(&result->color_f, line));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (ft_parse_color(&result->color_c, line));
	return (1);
}
