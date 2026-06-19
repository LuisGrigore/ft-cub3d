/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/19 21:25:32 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"
#include "../../../externals/libft/libft.h"
#include <stdlib.h>

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

static int	ft_load_textures(t_engine *engine, t_engine_config config)
{
	engine->no = ft_screen_texture_load(engine->screen,
			config.text_no_path);
	engine->so = ft_screen_texture_load(engine->screen,
			config.text_so_path);
	engine->we = ft_screen_texture_load(engine->screen,
			config.text_we_path);
	engine->ea = ft_screen_texture_load(engine->screen,
			config.text_ea_path);
	if (!engine->no || !engine->so || !engine->we || !engine->ea)
		return (-1);
	return (1);
}

static void	ft_set_hooks(t_engine *engine)
{
	ft_screen_x_hook(engine->screen,
		(t_hook){.func = ft_exit_next_frame, .param = engine});
	ft_screen_hook(engine->screen,
		(t_key_hook){2, 1L << 0, ft_key_press, engine});
	ft_screen_hook(engine->screen,
		(t_key_hook){3, 1L << 1, ft_player_key_release, &engine->player});
}

static int	ft_init_engine_screen(t_engine *engine)
{
	t_screen_config	sc;

	sc.width = WIDTH;
	sc.height = HEIGHT;
	sc.title = "Cub3D";
	sc.loop.func = ft_update;
	sc.loop.param = engine;
	engine->screen = ft_init_screen(sc);
	if (!engine->screen)
		return (-1);
	return (1);
}

t_engine	*ft_create_engine(t_engine_config config)
{
	t_engine	*engine;

	engine = ft_calloc(1, sizeof(t_engine));
	if (!engine)
		return (NULL);
	if (ft_init_engine_screen(engine) == -1)
		return (ft_destory_engine(engine), NULL);
	ft_init_player(&engine->player, config.player_config);
	engine->color_c = config.color_c;
	engine->color_f = config.color_f;
	engine->map = ft_copy_matrix(config.map);
	if (!engine->map)
		return (ft_destory_engine(engine), NULL);
	if (ft_load_textures(engine, config) == -1)
		return (ft_destory_engine(engine), NULL);
	engine->destroy_next_frame = false;
	ft_set_hooks(engine);
	return (engine);
}
