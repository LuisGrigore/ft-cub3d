/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_image_buffer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:27:42 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:18:12 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../config/screen_config.h"
#include "../../utils/utils.h"
#include "../mlx_instance_internal.h"
#include "mlx_instance_image_buffer.h"
#include <stdlib.h>

t_image	*init_image_buffer(void)
{
	t_image	*buffer;

	buffer = init_image(NULL, NULL, 0, 0, 0, 0, 0);
	buffer->img = mlx_new_image(mlx_get_instance()->mlx, WINDOW_X_SIZE,
			WINDOW_Y_SIZE);
	buffer->addr = mlx_get_data_addr(buffer->img, &buffer->bpp,
			&buffer->line_length, &buffer->endian);
	buffer->width = WINDOW_X_SIZE;
	buffer->height = WINDOW_Y_SIZE;
	if (!buffer)
	{
		mlx_destroy_image(mlx_get_instance()->mlx, buffer->img);
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

void	mlx_instance_add_image_to_buffer(t_image *img, t_vector2 position)
{
	int	i;
	int	j;
	int	color;
	int	pixel_index_grande;
	int	pixel_index_pequena;

	for (i = 0; i < img->height; i++)
	{
		for (j = 0; j < img->width; j++)
		{
			pixel_index_grande = ((position.y + i)
					* mlx_get_instance()->image_buffer->line_length)
				+ ((position.x + j) * (mlx_get_instance()->image_buffer->bpp
						/ 8));
			if ((position.y + i) < mlx_get_instance()->image_buffer->height
				&& (position.x + j) < mlx_get_instance()->image_buffer->width)
			{
				pixel_index_pequena = (i * img->line_length) + (j * (img->bpp
							/ 8));
				color = *(int *)(img->addr + pixel_index_pequena);
				if (color != -16777216)
				{
					*(int *)(mlx_get_instance()->image_buffer->addr
							+ pixel_index_grande) = color;
				}
			}
		}
	}
}

void	mlx_instance_clear_image_buffer(int color)
{
	t_image	*buffer;
	int		i;
	int		j;
	int		pixel_index;

	buffer = mlx_get_instance()->image_buffer;
	if (!buffer || !buffer->addr)
		return ;
	for (i = 0; i < buffer->height; i++)
	{
		for (j = 0; j < buffer->width; j++)
		{
			pixel_index = (i * buffer->line_length) + (j * (buffer->bpp / 8));
			*(int *)(buffer->addr + pixel_index) = color;
		}
	}
}

void	mlx_instance_draw_image_buffer(void)
{
	mlx_put_image_to_window(mlx_get_instance()->mlx,
		mlx_get_instance()->mlx_win, mlx_get_instance()->image_buffer->img, 0,
		0);
}
