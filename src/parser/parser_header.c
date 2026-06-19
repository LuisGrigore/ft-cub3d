/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
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

static int	ft_header_complete(t_parser_result *result)
{
	if (result->text_ea_path && result->text_no_path && result->text_so_path
		&& result->text_we_path && result->color_f >= 0 && result->color_c >= 0)
		return (1);
	return (0);
}

static void	ft_init_header(t_parser_result *result)
{
	result->text_no_path = NULL;
	result->text_so_path = NULL;
	result->text_ea_path = NULL;
	result->text_we_path = NULL;
	result->color_f = -1;
	result->color_c = -1;
}

int	ft_parser_header(t_parser_result *result, int fd)
{
	char	*line;
	int		line_num;

	ft_init_header(result);
	line_num = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_num++;
		ft_remove_spaces(&line);
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		if (ft_parser_header_line(result, line) == -1)
			return (printf("Error in line %d\n", line_num), free(line), -1);
		free(line);
		line = NULL;
		if (ft_header_complete(result))
			return (1);
	}
	return (-1);
}
