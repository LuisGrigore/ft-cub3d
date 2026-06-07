/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:03:39 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/03 14:03:20 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"
#include "../../../includes/player.h"
#include "../../../includes/config.h"

static int	touch(float x, float y, t_game *g)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK);
	map_y = (int)(y / BLOCK);
	if (!g->map || !g->map[map_y])
		return (1);
	return (g->map[map_y][map_x] == '1');
}

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
	if (keycode == ESC)
		exit(0);
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

void	ft_move_player(t_player *p, t_game *g)
{
	float	speed;
	float	nx;
	float	ny;

	speed = 3;
	if (p->key_up)
	{
		nx = p->x + cos(p->angle) * speed;
		ny = p->y + sin(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->key_down)
	{
		nx = p->x - cos(p->angle) * speed;
		ny = p->y - sin(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->key_left)
	{
		nx = p->x - sin(p->angle) * speed;
		ny = p->y + cos(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->key_right)
	{
		nx = p->x + sin(p->angle) * speed;
		ny = p->y - cos(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->left_rotate)
		p->angle -= 0.03;
	if (p->right_rotate)
		p->angle += 0.03;
}
