/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 23:15:22 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 22:36:42 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static int	set_texture(char **dst, const char *line, int start)
{
	int	end;

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


static int	ft_parse_header_line(t_header *head, const char *line)
{
	int	resp;

	resp = 0;
	if (ft_strncmp(line, "NO", 2) == 0)
		resp = set_texture(&head->text_no, line, 2);
	else if (ft_strncmp(line, "SO", 2) == 0)
		resp = set_texture(&head->text_so, line, 2);
	else if (ft_strncmp(line, "WE", 2) == 0)
		resp = set_texture(&head->text_we, line, 2);
	else if (ft_strncmp(line, "EA", 2) == 0)
		resp = set_texture(&head->text_ea, line, 2);
	else if (ft_strncmp(line, "F ", 2) == 0)
		resp = set_texture(&head->color_f, line, 1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		resp = set_texture(&head->color_c, line, 1);
	if (resp == -1)
		return (-1);
	return (resp);
}

static int	header_complete(t_header *header)
{
	if (!header)
		return (0);
	return (header->text_no && header->text_so && header->text_we
		&& header->text_ea && header->color_f && header->color_c);
}

static void	free_header(t_header *header)
{
	if (!header)
		return ;
	free(header->text_no);
	free(header->text_so);
	free(header->text_we);
	free(header->text_ea);
	free(header->color_f);
	free(header->color_c);
	free(header);
}

static char	*ft_getlines(int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	temp = ft_strtrim(line, "\n");
	free(line);
	return (temp);
}


static int	ft_check_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	ft_isnumeric(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_header_f_c(const char *line)
{
	int		i;
	int		num;
	int		count;
	char	**split;

	count = 0;
	split = ft_split(line, ',');
	if (!split)
		return (0);
	while (split[count])
		count++;
	if (count != 3)
		return (ft_free_split(split), 0);
	i = 0;
	while (i < 3)
	{
		if (!ft_isnumeric(split[i]))
			return (ft_free_split(split), 0);
		num = ft_atoi(split[i]);
		if (num < 0 || num > 255)
			return (ft_free_split(split), 0);
		i++;
	}
	ft_free_split(split);
	return (1);
}

static int	ft_check_header(t_header *h)
{
	if (!h->text_no || !h->text_so || !h->text_we || !h->text_ea)
		return (printf("Error: faltan texturas\n"), 0);
	if (!h->color_f || !h->color_c)
		return (printf("Error: faltan colores\n"), 0);
	if (!ft_check_file(h->text_no) || !ft_check_file(h->text_so)
		|| !ft_check_file(h->text_we) || !ft_check_file(h->text_ea))
		return (printf("Error: textura inválida\n"), 0);
	if (!ft_check_header_f_c(h->color_f) || !ft_check_header_f_c(h->color_c))
		return (printf("Error: color inválido\n"), 0);
	return (1);
}

t_header	*ft_create_header(int fd)
{
	char	*line;
	t_header	*header;
	int	resp;

	if (fd < 0)
		return (NULL);
	header = ft_calloc(1, sizeof(t_header));
	if (!header)
		return (NULL);
	while (1)
	{
		line = ft_getlines(fd);
		if (!line)
			break ;
		if (line[0] == '\0')
		{
			free(line);
			continue ;
		}
		resp = ft_parse_header_line(header, line);
		free(line);
		if (resp == -1)
		{
			free_header(header);
			return (NULL);
		}
		if (resp == 0)
		{
			free_header(header);
			return (NULL);
		}
		if (header_complete(header))
		{
			if (!ft_check_header(header))
			{
				free_header(header);
				return (NULL);
			}
			return (header);
		}
	}
	free_header(header);
	return (NULL);
}
