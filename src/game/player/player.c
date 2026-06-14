/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:03:39 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 15:09:42 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
// #include "../../../includes/engine.h"
#include "../../../includes/player.h"

void	ft_init_player(t_player *player, t_player_config config)
{
	player->x = config.starting_x;
	player->y = config.starting_y;
	player->angle = config.starting_angle;
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	ft_player_key_press(int keycode, void *player_ptr)
{
	t_player	*player;

	player = (t_player *)player_ptr;
	if (keycode == W)
		player->key_up = true;
	if (keycode == S)
		player->key_down = true;
	if (keycode == A)
		player->key_right = true;
	if (keycode == D)
		player->key_left = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	ft_player_key_release(int keycode, void *player_ptr)
{
	t_player	*player;

	player = (t_player *)player_ptr;
	if (keycode == W)
		player->key_up = false;
	if (keycode == S)
		player->key_down = false;
	if (keycode == A)
		player->key_right = false;
	if (keycode == D)
		player->key_left = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}
