/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:18:16 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/25 16:46:11 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

int	ft_read_map(t_parseo *parse, t_line **list)
{
	char	*lines[2];

	while ((lines[0] = get_next_line(parse->fd)))
	{
		lines[1] = ft_strtrim(lines[0], "\n");
		free(lines[0]);
		if (!lines[1])
			return (0);
		if (lines[1][0] == '\0')
		{
			free(lines[1]);
			continue;
		}
		ft_add_line(list, ft_new_line(lines[1]));
	}
	return (1);
}

static int ft_get_weigth(t_line *lst)
{
	t_line	*tmp;
	int		w;
	int		len;
	
	tmp = lst;
	w = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->text);
		if (w < len)
			w = len;
		tmp = tmp->next;
	}
	return (w);
}

static char	*ft_reg_line(char *line, int w)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(w + 1);
	if (!str)
		return (NULL);
	while(line[i])
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

char	**ft_norm_map(t_line *lst, t_parseo *parse)
{
	char	**map;
	t_line	*tmp;
	int		i;

	if (!lst)
		return (NULL);
	parse->map->len_max = ft_get_weigth(lst);
	map = ft_calloc(ft_len_lines(lst) + 1, sizeof(char *));
	if (!map)
		return (NULL);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		map[i] = ft_reg_line(tmp->text, parse->map->len_max);
		if (!map[i])
			return (ft_free_split(map), NULL);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	parse->map->height = i;
	ft_del_list(&lst);
	return (map);
}
