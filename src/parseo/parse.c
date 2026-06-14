/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:26:21 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 18:16:47 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static t_parseo	*ft_init_and_open(char *path)
{
	t_parseo	*parse;

	parse = malloc(sizeof(t_parseo));
	if (!parse)
		return (NULL);
	if (!ft_init_parse(parse))
		return (free(parse), NULL);
	parse->fd = open(path, O_RDONLY);
	if (parse->fd < 0)
		return (free(parse), NULL);
	return (parse);
}

static t_line	*ft_parse_header(t_parseo *parse)
{
	char	*line;
	t_line	*lst_map;

	line = ft_header(parse);
	if (!line)
		return (NULL);
	if (!ft_check_header(parse->header))
		return (free(line), NULL);
	lst_map = ft_new_line(line);
	free(line);
	return (lst_map);
}

static char	**ft_parse_map(t_parseo *parse, t_line **lst_map)
{
	char	**map;

	if (!ft_read_map(parse, lst_map))
		return (ft_del_list(lst_map), NULL);
	map = ft_norm_map(*lst_map, parse);
	if (!map)
		return (NULL);
	if (!ft_val_map(map, parse->map->height, parse))
		return (ft_free_split(map), NULL);
	return (map);
}

t_parse_result	*ft_parse(char *path)
{
	t_parseo		*parse;
	t_line			*lst_map;
	char			**map;
	t_parse_result	*final;
	
	parse = ft_init_and_open(path);
	if (!parse)
		return (NULL);
	lst_map = ft_parse_header(parse);
	if (!lst_map)
		return (ft_free_parseo(&parse), NULL);
	map = ft_parse_map(parse, &lst_map);
	if (!map)
		return (ft_free_parseo(&parse), NULL);
	parse->map->grid = map;
	final = ft_final_parse(parse);
	ft_free_parseo(&parse);
	return (final);
}

void	ft_delete_parse_result(t_parse_result **final)
{
	int	i;

	if (!final || !*final)
		return ;
	if ((*final)->map)
	{
		if ((*final)->map->grid)
		{
			i = 0;
			while ((*final)->map->grid[i])
				free((*final)->map->grid[i++]);
			free((*final)->map->grid);
		}
		free((*final)->map);
	}
	free((*final)->text_no);
	free((*final)->text_so);
	free((*final)->text_we);
	free((*final)->text_ea);
	free((*final)->color_f);
	free((*final)->color_c);
	free(*final);
	*final = NULL;
}
