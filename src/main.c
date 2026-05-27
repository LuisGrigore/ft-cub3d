/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/27 20:47:46 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parseo.h"
#include "../includes/game.h"
#include "../includes/player.h"
#include "../includes/config.h"
#include "../includes/screen_manager.h"

int	main(void)
{
	t_game			game;
	t_final_parse	*final;

	final = ft_parse();
	if (!final)
		return (printf("Error parse\n"), 1);

	init_game(&game, (t_game_config){
		.map = final->grid->map,
		.screen_width = WIDTH,
		.screen_height = HEIGHT,
		.title = "Cube3D",
		.player_starting_config = (t_player_config){
			.starting_x = final->f_player.starting_x * BLOCK,
			.starting_y = final->f_player.starting_y * BLOCK,
			.starting_angle = final->f_player.starting_angle
		}
	});
	game.colorF = final->colorF;
	game.colorC = final->colorC;
	start_game(&game);
	return (0);
}
