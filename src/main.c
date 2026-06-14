/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 18:15:57 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/engine.h"
#include "../includes/parseo.h"


int	main(int argc, char **argv)
{
	t_engine	*engine;
	t_parse_result	*parse_result;
	int ret;

	if (argc != 2)
		return (printf("Usage: %s <scene_path>\n", argv[0]), 1);
	
	parse_result = ft_parse(argv[1]);
	if (!parse_result)
		return (printf("Error parsing\n"), 1);
	engine = ft_create_engine((t_engine_config){
		.player_config = parse_result->f_player,
		.map = parse_result->map->grid,
		.colorF = parse_result->colorF,
		.colorC = parse_result->colorC,
		.text_no_path = parse_result->text_no,
		.text_so_path = parse_result->text_so,
		.text_we_path = parse_result->text_we,
		.text_ea_path = parse_result->text_ea
	});
	ft_delete_parse_result(&parse_result);
	if (!engine)
	{
		printf("Error creating engine\n");
		ft_destory_engine(engine);
		return (1);
	}
	ret = ft_start_engine(engine);
	if (ret != 0)
		printf("Error during engine execution\n");
	ft_destory_engine(engine);
	return (ret);
}
