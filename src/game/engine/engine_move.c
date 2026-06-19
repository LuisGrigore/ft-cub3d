/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/19 21:22:31 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/engine.h"
#include "../../../includes/config.h"
#include "../../../externals/libft/libft.h"
#include <stdlib.h>
#include <math.h>

static int	touch(float x, float y, t_engine *g)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK);
	map_y = (int)(y / BLOCK);
	if (!g->map || !g->map[map_y])
		return (1);
	return (g->map[map_y][map_x] == '1');
}

static void	ft_move_forward_back(t_engine *engine, float speed)
{
	float	nx;
	float	ny;

	if (engine->player.key_up)
	{
		nx = engine->player.x + cos(engine->player.angle) * speed;
		ny = engine->player.y + sin(engine->player.angle) * speed;
		if (!touch(nx, engine->player.y, engine))
			engine->player.x = nx;
		if (!touch(engine->player.x, ny, engine))
			engine->player.y = ny;
	}
	if (engine->player.key_down)
	{
		nx = engine->player.x - cos(engine->player.angle) * speed;
		ny = engine->player.y - sin(engine->player.angle) * speed;
		if (!touch(nx, engine->player.y, engine))
			engine->player.x = nx;
		if (!touch(engine->player.x, ny, engine))
			engine->player.y = ny;
	}
}

static void	ft_apply_speed(t_engine *engine, float speed)
{
	float	nx;
	float	ny;

	if (engine->player.key_left)
	{
		nx = engine->player.x - sin(engine->player.angle) * speed;
		ny = engine->player.y + cos(engine->player.angle) * speed;
		if (!touch(nx, engine->player.y, engine))
			engine->player.x = nx;
		if (!touch(engine->player.x, ny, engine))
			engine->player.y = ny;
	}
	if (engine->player.key_right)
	{
		nx = engine->player.x + sin(engine->player.angle) * speed;
		ny = engine->player.y - cos(engine->player.angle) * speed;
		if (!touch(nx, engine->player.y, engine))
			engine->player.x = nx;
		if (!touch(engine->player.x, ny, engine))
			engine->player.y = ny;
	}
	if (engine->player.left_rotate)
		engine->player.angle -= 0.03;
	if (engine->player.right_rotate)
		engine->player.angle += 0.03;
}

void	ft_move_player(t_engine *engine)
{
	float	speed;

	speed = 3;
	ft_move_forward_back(engine, speed);
	ft_apply_speed(engine, speed);
}

void	ft_destory_engine(t_engine *engine)
{
	int	i;

	if (!engine)
		return ;
	ft_screen_texture_destroy(engine->screen, engine->no);
	ft_screen_texture_destroy(engine->screen, engine->so);
	ft_screen_texture_destroy(engine->screen, engine->we);
	ft_screen_texture_destroy(engine->screen, engine->ea);
	if (engine->map)
	{
		i = 0;
		while (engine->map[i])
			free(engine->map[i++]);
		free(engine->map);
	}
	ft_screen_destroy(engine->screen);
	free(engine);
}
