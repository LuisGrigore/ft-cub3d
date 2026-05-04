/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:26:31 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:17:35 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../config/screen_config.h"
#include "../utils/utils.h"
#include "mlx_instance.h"
#include "mlx_instance_internal.h"
#include <stdlib.h>

int	mlx_instance_init(int width, int height, char *title)
{
	t_mlx_instance	*mlx_instance;
	int				ret;

	mlx_instance = mlx_get_instance();
	mlx_instance->mlx = mlx_init();
	ret = 1;
	if (!mlx_instance->mlx)
		return (0);
	mlx_instance->mlx_win = mlx_new_window(mlx_instance->mlx, width, height,
			title);
	if (!mlx_instance->mlx_win)
		return (0);
	mlx_instance->key_functs = init_list();
	if (!mlx_instance->key_functs)
		return (0);
	mlx_instance->text_buffer = init_list();
	if (!mlx_instance->text_buffer)
		return (0);
	mlx_instance->image_buffer = init_image_buffer();
	if (!mlx_instance->image_buffer)
		return (0);
	mlx_key_hook(mlx_instance->mlx_win, key_hook, NULL);
}

t_mlx_instance	*mlx_get_instance(void)
{
	static t_mlx_instance	*mlx_instance = NULL;

	if (!mlx_instance)
		mlx_instance = ft_calloc(1, sizeof(t_mlx_instance));
	return (mlx_instance);
}

void	mlx_instance_start_loop(void)
{
	mlx_loop(mlx_get_instance()->mlx);
}

void	mlx_instance_destroy(void)
{
	t_mlx_instance	*instance;

	instance = mlx_get_instance();
	if (instance->image_buffer)
		mlx_instance_unload_image(instance->image_buffer);
	if (instance->key_functs)
		destroy_list(instance->key_functs, free);
	if (instance->text_buffer)
		destroy_list(instance->text_buffer, destroy_screen_text);
	if (instance->mlx_win)
		mlx_destroy_window(instance->mlx, instance->mlx_win);
	if (instance->mlx)
		mlx_destroy_display(instance->mlx);
	free(instance->mlx);
	free(instance);
}
