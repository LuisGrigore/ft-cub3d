/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 15:51:21 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"

#include "../../../externals/minilibx-linux/mlx.h"

static void	ft_draw_line(t_engine *g, float angle, int x)
{
	t_ray	r;

	ft_init_ray(&r, g, angle);
	ft_calc_step(&r, g);
	ft_perform_dda(&r, g);
	ft_calc_wall(&r, g);
	ft_draw_wall(g, &r, x);
}

static int	ft_update(void *engine_ptr)
{
	t_engine	*engine;
	float		fov;
	float		angle;
	float		step;
	int			i;

	
	engine = engine_ptr;
	if (engine->destroy_next_frame)
		return (ft_close(0, engine));
	ft_move_player(&engine->player, engine);
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

void	ft_start_engine(t_engine *g)
{
	ft_screen_start(&g->screen);
}

static void	ft_load_texture(t_engine *g, t_texture *tex, char *path)
{
	if (ft_screen_texture_load(&g->screen, tex, path) != 0)
		ft_free_engine(g);
}
#include <stdio.h>
static int ft_exit_next_frame(void *param)
{
	t_engine	*g;
	
	g = (t_engine *)param;

	g->destroy_next_frame = true;
	return 0;
}

static int ft_key_press(int keycode, void *param)
{
	t_engine *engine = (t_engine *)param;

	if (keycode == ESC)
		ft_exit_next_frame(param);

	return ft_player_key_press(keycode, (void*) &engine->player);

}

void	ft_init_engine(t_engine *g)
{
	ft_init_screen(&g->screen, &(t_screen_config){.width = WIDTH,
		.height = HEIGHT, .title = "Cub3D",
		.loop = (t_loop_hook){.func = ft_update, .param = g}});
	
	ft_init_player(&g->player, g->final->f_player);
	g->colorC = g->final->colorC;
	g->colorF = g->final->colorF;
	g->map = g->final->grid->map;
	ft_load_texture(g, &g->no, g->final->text_no);
	ft_load_texture(g, &g->so, g->final->text_so);
	ft_load_texture(g, &g->we, g->final->text_we);
	ft_load_texture(g, &g->ea, g->final->text_ea);
	g->destroy_next_frame = false;
	ft_screen_x_hook(&g->screen, (t_loop_hook){.func = ft_exit_next_frame, .param = g});
	ft_screen_hook(&g->screen, (t_screen_hook){2, 1L << 0, ft_key_press,
		g});
	ft_screen_hook(&g->screen, (t_screen_hook){3, 1L << 1,
		ft_player_key_release, &g->player});
}
