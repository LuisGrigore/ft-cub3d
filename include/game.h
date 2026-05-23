/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:44:50 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/23 17:15:59 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../external/mlx/mlx.h"
# include "./player.h"
# include "./screen_manager.h"
# include <stdbool.h>

typedef struct s_game
{
	t_screen		screen;
	t_player		player;
	char			**map;
}					t_game;

typedef struct s_game_config
{
	int				screen_width;
	int				screen_height;
	char			*title;
	t_player_config	player_starting_config;
	char			**map;
}					t_game_config;

void				init_game(t_game *game, t_game_config config);
void				start_game(t_game *game);

#endif