/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/15 03:50:47 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"
#include "../../../externals/libft/libft.h"
#include <stdlib.h>
# include <math.h>


static void	ft_draw_line(t_engine *g, float angle, int x)
{
	t_ray	r;

	ft_init_ray(&r, g, angle);
	ft_calc_step(&r, g);
	ft_perform_dda(&r, g);
	ft_calc_wall(&r, g);
	ft_draw_wall(g, &r, x);
}

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

static void	ft_move_player(t_engine *engine)
{
	float	speed;
	float	nx;
	float	ny;

	speed = 3;
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
	ft_apply_speed(engine, speed);
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
	return ft_screen_start(g->screen);
}

// static void	ft_load_texture(t_engine *g, t_texture *tex, char *path)
// {
// 	if (ft_screen_texture_load(g->screen, path) != 0)
// 		ft_destory_engine(g);
// }
static int ft_exit_next_frame(void *engine_ptr)
{
	t_engine	*engine;
	
	engine = (t_engine *)engine_ptr;
	engine->destroy_next_frame = true;
	return 0;
}

static int ft_key_press(int keycode, void *engine_ptr)
{
	t_engine *engine = (t_engine *)engine_ptr;

	if (keycode == ESC)
		ft_exit_next_frame(engine_ptr);

	return ft_player_key_press(keycode, (void*) &engine->player);

}

char	**ft_copy_matrix(char **matrix)
{
	char	**copy;
	int		rows;
	int		i;

	rows = 0;
	while (matrix[rows])
		rows++;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = ft_strdup(matrix[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

t_engine	*ft_create_engine(t_engine_config config)
{
	t_engine *engine;
	
	engine = ft_calloc(1, sizeof(t_engine));
	if (!engine)
		return (NULL);
		
	engine->screen = ft_init_screen((t_screen_config){.width = WIDTH,
		.height = HEIGHT, .title = "Cub3D",
		.loop = (t_hook){.func = ft_update, .param = engine}});
	
	ft_init_player(&engine->player, config.player_config);
	engine->colorC = config.colorC;
	engine->colorF = config.colorF;
	engine->map = ft_copy_matrix(config.map);
	if (!engine->map)
	    return (ft_destory_engine(engine), NULL);

	engine->no = ft_screen_texture_load(engine->screen, config.text_no_path);
	engine->so = ft_screen_texture_load(engine->screen, config.text_so_path);
	engine->we = ft_screen_texture_load(engine->screen, config.text_we_path);
	engine->ea = ft_screen_texture_load(engine->screen, config.text_ea_path);
	if (!engine->no || !engine->so || !engine->we || !engine->ea)
	    return (ft_destory_engine(engine), NULL);

	engine->destroy_next_frame = false;
	ft_screen_x_hook(engine->screen, (t_hook){.func = ft_exit_next_frame, .param = engine});
	ft_screen_hook(engine->screen, (t_key_hook){2, 1L << 0, ft_key_press,
		engine});
	ft_screen_hook(engine->screen, (t_key_hook){3, 1L << 1,
		ft_player_key_release, &engine->player});
	return (engine);
}
void	ft_destory_engine(t_engine *engine)
{
	if (!engine)
		return ;
	ft_screen_texture_destroy(engine->screen, engine->no);
	ft_screen_texture_destroy(engine->screen, engine->so);
	ft_screen_texture_destroy(engine->screen, engine->we);
	ft_screen_texture_destroy(engine->screen, engine->ea);
	int	i;
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
