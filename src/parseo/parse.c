/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:26:21 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/15 18:35:05 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_delete_list(t_line **list)
{
	t_line	*tmp;
	t_line	*lst;

	lst = *list;
	while (lst)
	{
		tmp = lst->next;
		free(lst->text);
		free(lst);
		lst = tmp;
	}
	*list = NULL;
}

void	ft_add_line(t_line *lst, t_line *new)
{
	t_line	*tmp;

	if (!lst || !new)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_line	*ft_new_line(char *line)
{
	t_line	*lst;

	if (!line)
		return (NULL);
	lst = (t_line *)ft_calloc(1, sizeof(t_line));
	if (!lst)
		return (NULL);
	lst->text = ft_strdup(line);
	lst->next = NULL;
	return (lst);
}

t_line	*ft_get_map_line_list(int fd)
{
	char	*line;
	char	*temp;
	t_line	*list;

	line = get_next_line(fd);
	list = NULL;
	while (line)
	{
		temp = ft_strtrim(line, "\n");
		free(line);
		if (!temp)
		{
			ft_delete_list(&list);
			return (NULL);
		}
		if (temp[0] == '\0')
		{
			free(temp);
			line = get_next_line(fd);
			continue ;
		}
		if (!list)
			list = ft_new_line(temp);
		else
			ft_add_line(list, ft_new_line(temp));
		free(temp);
		line = get_next_line(fd);
	}
	return (list);
}

static char	*ft_reg_line(char *line, int w)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(w + 1);
	if (!str)
		return (NULL);
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (i < w)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_get_width(t_line *lst)
{
	t_line	*tmp;
	int		max_width;
	int		len;

	tmp = lst;
	max_width = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->text);
		if (max_width < len)
			max_width = len;
		tmp = tmp->next;
	}
	return (max_width);
}

int	ft_len_lines(t_line *list)
{
	t_line	*tmp;
	int		i;

	if (!list)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**ft_norm_map(t_line *lst)
{
	char	**map;
	t_line	*tmp;
	int		i;

	if (!lst)
		return (NULL);
	map = ft_calloc(ft_len_lines(lst) + 1, sizeof(char *));
	if (!map)
		return (NULL);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		map[i] = ft_reg_line(tmp->text, ft_get_width(lst));
		if (!map[i])
			return (ft_free_split(map), NULL);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	ft_parse_map(t_parse_result *result, int fd)
{
	t_line	*line;

	line = ft_get_map_line_list(fd);
	if (!line)
		return (-1);
	result->map = ft_norm_map(line);
	ft_delete_list(&line);
	return (1);
}

int	ft_skip_spc(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i += 1;
	return (i);
}

void	ft_remove_spaces(char **str)
{
	int		i;
	char	*temp;

	i = ft_skip_spc(*str);
	temp = *str;
	*str = ft_strdup(temp + i);  // FIX: era str[i] en vez de temp+i
	free(temp);
}

int	ft_len_dir(const char *line, int start)
{
	int	len;

	len = start;
	while (line[len] && line[len] != ' ' && line[len] != '\t'
		&& line[len] != '\n')
		len++;
	return (len);
}

static char	*ft_get_header_line_content(const char *line, int start)
{
	int	end;

	start += ft_skip_spc(line + start);  // FIX: pasar puntero desplazado, no índice doble
	end = ft_len_dir(line, start);
	if (end <= start)
		return (NULL);
	return ft_substr(line, start, end - start);
}

static int	ft_rgb_to_int(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if (!rgb)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_split(rgb);
	return ((r << 16) | (g << 8) | b);
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

static int	ft_check_color(const char *line)
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

static int	ft_parse_header_line(t_parse_result *result, const char *line)
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


int	ft_parse_header(t_parse_result *result, int fd)
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
		if (ft_parse_header_line(result, line) == -1)
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

int	ft_parse_player_spawn(t_parse_result *result)
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

void	ft_delete_parse_result(t_parse_result *final)
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

#include <stdio.h>
int ft_validate_map_chars(t_parse_result *result)
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

static int	ft_check_map_closed(t_parse_result *result)
{
	int	i;
	int	j;
	char ** map = result->map;

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


static int	ft_check_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	ft_check_header(t_parse_result *result)
{
	if (!result->text_no_path || !result->text_so_path || !result->text_we_path || !result->text_ea_path)
		return (printf("Error: faltan texturas\n"), -1);
	if (result->colorF == -1 || result->colorC == -1)
		return (printf("Error: faltan colores\n"), -1);
	if (!ft_check_file(result->text_no_path) || !ft_check_file(result->text_so_path)
		|| !ft_check_file(result->text_we_path) || !ft_check_file(result->text_ea_path))
		return (printf("Error: textura inválida\n"), -1);

	return (1);
}

t_parse_result	*ft_parse(char *path)
{
	t_parse_result	*result;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = malloc(sizeof(t_parse_result));
	if (!result)
		return (close(fd), NULL);
	result->map = NULL;
	if (ft_parse_header(result, fd) == -1)
	{
		printf("Error parsing header\n");
		return (close(fd), ft_delete_parse_result(result), NULL);
	}
	if (ft_check_header(result) == -1)
	{
		printf("Error: invalid header\n");
		return (close(fd), ft_delete_parse_result(result), NULL);
	}
	if (ft_parse_map(result, fd) == -1)
	{
		printf("Error parsing map\n");
		return (close(fd), ft_delete_parse_result(result), NULL);
	}
	close(fd);
	if (ft_validate_map_chars(result) == -1)
	{
		printf("Error: invalid char in map\n");
		return (ft_delete_parse_result(result), NULL);
	}
	if (ft_check_map_closed(result) == -1)
	{
		printf("Error: map not closed\n");
		return (ft_delete_parse_result(result), NULL);
	}
	if (ft_parse_player_spawn(result) == -1)
	{
		printf("Error parsing player\n");
		return (ft_delete_parse_result(result), NULL);
	}
	return (result);
}

