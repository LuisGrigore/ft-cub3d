/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/19 21:23:13 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"
#include <math.h>
#include <stdlib.h>

int	ft_exit_next_frame(void *engine_ptr)
{
	t_engine	*engine;

	engine = (t_engine *)engine_ptr;
	engine->destroy_next_frame = true;
	return (0);
}

int	ft_key_press(int keycode, void *engine_ptr)
{
	t_engine	*engine;

	engine = (t_engine *)engine_ptr;
	if (keycode == ESC)
		ft_exit_next_frame(engine_ptr);
	return (ft_player_key_press(keycode, (void *)&engine->player));
}

static void	ft_draw_line(t_engine *g, float angle, int x)
{
	t_ray	r;

	ft_init_ray(&r, g, angle);
	ft_calc_step(&r, g);
	ft_perform_dda(&r, g);
	ft_calc_wall(&r, g);
	ft_draw_wall(g, &r, x);
}

int	ft_update(void *engine_ptr)
{
	t_engine	*engine;
	float		fov;
	float		angle;
	float		step;
	int			i;

	engine = engine_ptr;
	if (engine->destroy_next_frame)
		return (ft_screen_stop(engine->screen));
	ft_move_player(engine);
	fov = PI / 3;
	angle = engine->player.angle - fov / 2;
	step = fov / WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		ft_draw_line(engine, angle, i);
		angle += step;
		i++;
	}
	return (0);
}

int	ft_start_engine(t_engine *g)
{
	return (ft_screen_start(g->screen));
}
