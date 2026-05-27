/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 23:15:22 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/24 17:17:42 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static int	set_texture(char **dst, const char *line, int start)
{
	int		end;

	if (*dst)
		return (printf("Error: textura duplicada\n"), -1);
	ft_skip_spc(line, &start);
	end = ft_len_dir(line, start);
	if (end <= start)
		return (printf("Error: ruta inválida\n"), -1);
	*dst = ft_substr(line, start, end - start);
	if (!*dst)
		return (-1);
	return (1);
}

int ft_inst_header(t_header **head, const char *line)
{
	int	resp;
	
	resp = 0;
	if (ft_strncmp(line, "NO", 2) == 0)
		resp = set_texture(&(*head)->text_no, line, 2);
	else if (ft_strncmp(line, "SO", 2) == 0)
		resp = set_texture(&(*head)->text_so, line, 2);
	else if (ft_strncmp(line, "WE", 2) == 0)
		resp = set_texture(&(*head)->text_we, line, 2);
	else if (ft_strncmp(line, "EA", 2) == 0)
		resp = set_texture(&(*head)->text_ea, line, 2);
	else if (ft_strncmp(line, "F ", 2) == 0)
		resp = set_texture(&(*head)->color_f, line, 1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		resp = set_texture(&(*head)->color_c, line, 1);
	if (resp == -1)
		return (-1);
	return (resp);
}

char	*ft_header(t_parseo *parse)
{
	char	*lines[2];
	int		ret;

	while ((lines[0] = get_next_line(parse->fd)))
	{
		lines[1] = ft_strtrim(lines[0], "\n");
		free(lines[0]);
		if (!lines[1])
			return (NULL);
		if (lines[1][0] == '\0')
		{
			free(lines[1]);
			continue ;
		}
		ret = ft_inst_header(&parse->header, lines[1]);
		if (ret == -1)
			return (free(lines[1]), NULL);
		if (ret == 1)
		{
			free(lines[1]);
			continue ;
		}
		return (lines[1]);
	}
	return (NULL);
}
