/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:27:01 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/02 19:20:54 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"
#include "../../includes/config.h"
#include "../../includes/player.h"

int	ft_rgb_to_int(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if(!rgb)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_split(rgb);
	return ((r << 16) | (g << 8) | b);
}


t_final_parse	*ft_final_parse(t_parseo *parse)
{
	t_final_parse	*final;

	final = ft_calloc(1, sizeof(t_final_parse));
	if (!final)
		return (NULL);
	//Me falta lo del angulo
	final->grid = ft_create_grid(parse->map);
	final->colorC = ft_rgb_to_int(parse->header->color_c);
	final->colorF = ft_rgb_to_int(parse->header->color_f);
	final->f_player.starting_x = (parse->player_x + 0.5) * BLOCK;
	final->f_player.starting_y = (parse->player_y + 0.5) * BLOCK;
	final->text_no = ft_strdup(parse->header->text_no);
	final->text_ea = ft_strdup(parse->header->text_ea);
	final->text_we = ft_strdup(parse->header->text_we);
	final->text_so = ft_strdup(parse->header->text_so);
	if (parse->player_dir == 'N')
		final->f_player.starting_angle = -PI / 2;
	else if (parse->player_dir == 'S')
		final->f_player.starting_angle = PI / 2;
	else if (parse->player_dir == 'W')
		final->f_player.starting_angle = PI;
	else  // 'E'
		final->f_player.starting_angle = 0;
	return (final);
}

