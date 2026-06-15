/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/15 03:55:40 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/engine.h"
#include "../includes/parseo.h"

#include <stdio.h>

void	ft_print_parse_result(t_parse_result *result)
{
	int	i;

	if (!result)
	{
		printf("parse_result: NULL\n");
		return ;
	}
	printf("=== t_parse_result ===\n");
	printf("text_no_path : %s\n", result->text_no_path ? result->text_no_path : "(null)");
	printf("text_so_path : %s\n", result->text_so_path ? result->text_so_path : "(null)");
	printf("text_we_path : %s\n", result->text_we_path ? result->text_we_path : "(null)");
	printf("text_ea_path : %s\n", result->text_ea_path ? result->text_ea_path : "(null)");
	printf("colorF       : %d (r=%d g=%d b=%d)\n",
		result->colorF,
		(result->colorF >> 16) & 0xFF,
		(result->colorF >> 8) & 0xFF,
		result->colorF & 0xFF);
	printf("colorC       : %d (r=%d g=%d b=%d)\n",
		result->colorC,
		(result->colorC >> 16) & 0xFF,
		(result->colorC >> 8) & 0xFF,
		result->colorC & 0xFF);
	printf("starting_x   : %.2f\n", result->starting_x);
	printf("starting_y   : %.2f\n", result->starting_y);
	printf("starting_angle: %.4f\n", result->starting_angle);
	printf("map:\n");
	if (!result->map)
	{
		printf("  (null)\n");
		return ;
	}
	i = 0;
	while (result->map[i])
	{
		printf("  [%3d] |%s|\n", i, result->map[i]);
		i++;
	}
	printf("======================\n");
}


void	ft_print_engine(t_engine *engine)
{
	int	i;

	if (!engine)
	{
		printf("engine: NULL\n");
		return ;
	}
	printf("=== t_engine ===\n");
	printf("screen           : %p\n", (void *)engine->screen);
	printf("colorF           : %d (r=%d g=%d b=%d)\n",
		engine->colorF,
		(engine->colorF >> 16) & 0xFF,
		(engine->colorF >> 8) & 0xFF,
		engine->colorF & 0xFF);
	printf("colorC           : %d (r=%d g=%d b=%d)\n",
		engine->colorC,
		(engine->colorC >> 16) & 0xFF,
		(engine->colorC >> 8) & 0xFF,
		engine->colorC & 0xFF);
	printf("destroy_next_frame: %s\n", engine->destroy_next_frame ? "true" : "false");
	printf("no               : %p\n", (void *)engine->no);
	printf("so               : %p\n", (void *)engine->so);
	printf("we               : %p\n", (void *)engine->we);
	printf("ea               : %p\n", (void *)engine->ea);
	printf("map:\n");
	if (!engine->map)
		printf("  (null)\n");
	else
	{
		i = 0;
		while (engine->map[i])
		{
			printf("  [%3d] |%s|\n", i, engine->map[i]);
			i++;
		}
	}
	printf("================\n");
}

int	main(int argc, char **argv)
{
	t_engine	*engine;
	t_parse_result	*parse_result;
	int ret = 0;

	if (argc != 2)
		return (printf("Usage: %s <scene_path>\n", argv[0]), 1);
	
	parse_result = ft_parse(argv[1]);
	if (!parse_result)
		return (printf("Error parsing\n"), 1);
	ft_print_parse_result(parse_result);
	engine = ft_create_engine((t_engine_config){
		.player_config = (t_player_config) {.starting_angle = parse_result->starting_angle,
		.starting_x = parse_result->starting_x, .starting_y = parse_result->starting_y},
		.map = parse_result->map,
		.colorF = parse_result->colorF,
		.colorC = parse_result->colorC,
		.text_no_path = parse_result->text_no_path,
		.text_so_path = parse_result->text_so_path,
		.text_we_path = parse_result->text_we_path,
		.text_ea_path = parse_result->text_ea_path
	});
	ft_print_engine(engine);
	ft_delete_parse_result(parse_result);
	parse_result = NULL;
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
