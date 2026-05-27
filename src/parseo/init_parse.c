/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:17 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/22 23:15:44 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static void ft_init_header(t_header **header)
{
	(*header)->text_no = NULL;
	(*header)->text_so = NULL;
	(*header)->text_we = NULL;
	(*header)->text_ea = NULL;
	(*header)->color_f = NULL;
	(*header)->color_c = NULL;
}

static void ft_init_map(t_map **map)
{
	(*map)->map = NULL;
	(*map)->height = 0;
	(*map)->len_max = 0;
}

int	ft_init_parse(t_parseo *parse)
{
	parse->header = ft_calloc(1, sizeof(t_header));
	if (!parse->header)
		return (0);
	ft_init_header(&parse->header);
	parse->map = ft_calloc(1, sizeof(t_map));
	if (!parse->map)
		return (0);
	ft_init_map(&parse->map);
	parse->player_x = 0.0;
	parse->player_y = 0.0;
	parse->fd = -1;
	parse->i = 0;
	parse->player_dir = 'x';
	return (1);
}

