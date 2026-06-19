/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/18 17:49:57 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/engine.h"
#include "../includes/parser.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_engine	*engine;
	t_parser_result	*parser_result;
	int ret = 0;

	if (argc != 2)
		return (printf("Usage: %s <scene_path>\n", argv[0]), 1);
	
	parser_result = ft_parser(argv[1]);
	if (!parser_result)
		return (printf("Error parsing\n"), 1);
	engine = ft_create_engine((t_engine_config){
		.player_config = (t_player_config) {.starting_angle = parser_result->starting_angle,
		.starting_x = parser_result->starting_x, .starting_y = parser_result->starting_y},
		.map = parser_result->map,
		.colorF = parser_result->colorF,
		.colorC = parser_result->colorC,
		.text_no_path = parser_result->text_no_path,
		.text_so_path = parser_result->text_so_path,
		.text_we_path = parser_result->text_we_path,
		.text_ea_path = parser_result->text_ea_path
	});
	ft_delete_parser_result(parser_result);
	parser_result = NULL;
	if (!engine)
	{
		printf("Error creating engine\n");
		return (1);
	}
	ret = ft_start_engine(engine);
	if (ret != 0)
		printf("Error during engine execution\n");
	ft_destory_engine(engine);
	return (ret);
}
