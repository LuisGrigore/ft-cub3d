/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:10:26 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/26 15:10:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include "../../includes/game.h"
#include "stdio.h"
#include <math.h>
#include <stdlib.h>


static int	key_release_wrapper(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65307)
		exit(0);
	return (player_key_release(keycode, &game->player));
}

static float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - game->player.angle;
	fix_dist = sqrt(delta_x * delta_x + delta_y * delta_y) * cos(angle);
	return (fix_dist);
}


static bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	if (!game->map)
		return (false);
	if (y < 0 || y > 9)
		return (true);
	if (x < 0 || x > 14)
		return (true);
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

static void	draw_line(t_game *game, float angle, int column)
{
	float		cos_angle;
	float		sin_angle;
	float		ray_x;
	float		ray_y;
	float		dist;
	float		height;
	int			start_y;
	int			end;
	int			steps;
	const float	step_size = 0.1f;
	const float	max_distance = 20 * BLOCK;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	ray_x = game->player.x;
	ray_y = game->player.y;
	steps = 0;
	while (!touch(ray_x, ray_y, game) && steps < (int)(max_distance
			/ step_size))
	{
		ray_x += cos_angle * step_size;
		ray_y += sin_angle * step_size;
		steps++;
	}
	dist = fixed_dist(game->player.x, game->player.y, ray_x, ray_y, game);
	if (dist > 0)
	{
		height = (BLOCK / dist) * (game->screen.width / 2);
		start_y = (game->screen.height - (int)height) / 2;
		end = start_y + (int)height;
		if (end > game->screen.height)
			end = game->screen.height;
		while (start_y < end && start_y >= 0)
		{
			put_pixel(column, start_y, 255, &game->screen);
			start_y++;
		}
	}
}
static void	draw_loop(void *param)
{
	t_game		*game;
	t_player	*player;
	float		fraction;
	float		start_x;
	int			i;

	game = (t_game *)param;
	player = &game->player;
	move_player(player);
	clear_image(&game->screen);
	fraction = PI / 3 / WIDTH;
	start_x = player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(game, start_x, i);
		start_x += fraction;
		i++;
	}
}
void	init_game(t_game *game, t_game_config config)
{
	init_player(&game->player, config.player_starting_config);
	game->map = config.map;
	init_screen(&game->screen, (t_screen_config){.height = config.screen_height,
		.width = config.screen_width, .title = config.title,
		.loop = (t_loop_hook){.func = draw_loop, .param = game}});
	set_hook(&game->screen, (t_screen_hook){.event = SCREEN_KEY_PRESS,
		.func = player_key_press, .mask = SCREEN_KEY_PRESS,
		.param = &game->player});
	set_hook(&game->screen, (t_screen_hook){.event = SCREEN_KEY_RELEASE,
		.func = key_release_wrapper, .mask = SCREEN_KEY_RELEASE,
		.param = game});
}

void	start_game(t_game *game)
{
	start_screen(&game->screen);
}
