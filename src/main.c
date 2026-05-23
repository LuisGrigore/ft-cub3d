/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:22:28 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/23 17:26:03 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/config.h"
#include "../include/game.h"
#include <stdlib.h>

// DEBUG
char	**get_map(void)
{
	static const char	*map_data[] = {"111111111111111", "100000000000001",
			"100000000000001", "100000100000001", "100000000000001",
			"100000010000001", "100001000000001", "100000000000001",
			"100000000000001", "111111111111111", NULL};
	char				**map;
	int					i;

	map = malloc(sizeof(char *) * 11);
	if (!map)
		return (NULL);
	i = 0;
	while (map_data[i] != NULL)
	{
		map[i] = (char *)map_data[i];
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	main(void)
{
	t_game	game;

	init_game(&game, (t_game_config){.map = get_map(), .screen_width = WIDTH,
		.screen_height = HEIGHT, .title = "Cube3D",
		.player_starting_config = (t_player_config){.starting_angle = PI / 2,
		.starting_x = WIDTH / 2, .starting_y = HEIGHT / 2}});
	start_game(&game);
	return (0);
}
