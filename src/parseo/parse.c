/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:26:21 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/02 19:31:22 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

t_final_parse	*ft_parse()
{
	t_parseo		*parse;
	char			*line;
	t_line			*lst_map;
	char			**map;
	t_final_parse	*final;

	lst_map = NULL;
	parse = malloc(sizeof(t_parseo));
	if (!parse)
		return (NULL);
	if (!ft_init_parse(parse))
		return (free(parse), NULL);
	parse->fd = open("media/maps/firstMap.cub", O_RDONLY);
	if (parse->fd < 0)
		return (free(parse), NULL);
	line = ft_header(parse);
	if (!line)
		return (ft_free_parseo(&parse), NULL);
	if (!ft_check_header(parse->header))
		return (free(line), ft_free_parseo(&parse), NULL);
	lst_map = ft_new_line(line);
	free(line);
	if (!ft_read_map(parse, &lst_map))
		return (ft_del_list(&lst_map), ft_free_parseo(&parse), NULL);
	map = ft_norm_map(lst_map, parse);
	if (!map)
		return (ft_free_parseo(&parse), NULL);
	if (!ft_val_map(map, parse->map->height, parse))
		return (ft_free_split(map), ft_free_parseo(&parse), NULL);
	parse->map->map = map;
	final = ft_final_parse(parse);
	ft_free_parseo(&parse);
	return (final);
}
