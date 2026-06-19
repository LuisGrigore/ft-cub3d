/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/19 21:25:32 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"
#include "../includes/parser.h"
#include <stdio.h>

static int	ft_check_engine(t_engine *e)
{
	int	ret;

	ret = 0;
	if (!e)
	{
		printf("Error creating engine\n");
		return (0);
	}
	ret = ft_start_engine(e);
	if (ret != 0)
		printf("Error during engine execution\n");
	ft_destory_engine(e);
	return (1);
}

int	main(int argc, char **argv)
{
	t_engine		*e;
	t_parser_result	*p;
	t_engine_config	ec;

	if (argc != 2)
		return (printf("Usage: %s <scene_path>\n", argv[0]), 1);
	p = ft_parser(argv[1]);
	if (!p)
		return (printf("Error parsing\n"), 1);
	ec.player_config.starting_angle = p->s_angle;
	ec.player_config.starting_x = p->starting_x;
	ec.player_config.starting_y = p->starting_y;
	ec.map = p->map;
	ec.color_f = p->color_f;
	ec.color_c = p->color_c;
	ec.text_no_path = p->text_no_path;
	ec.text_so_path = p->text_so_path;
	ec.text_we_path = p->text_we_path;
	ec.text_ea_path = p->text_ea_path;
	e = ft_create_engine(ec);
	ft_delete_parser_result(p);
	p = NULL;
	if (!ft_check_engine(e))
		return (1);
	return (0);
}
