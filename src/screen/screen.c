/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:01:52 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/14 15:38:18 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../includes/screen.h"
#include <stdlib.h>

void	ft_init_screen(t_screen *screen, t_screen_config *config)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, config->width, config->height,
			config->title);
	screen->buffer.img = mlx_new_image(screen->mlx, config->width,
			config->height);
	screen->buffer.data = mlx_get_data_addr(screen->buffer.img,
			&screen->buffer.bpp, &screen->buffer.line_len,
			&screen->buffer.endian);
	screen->buffer.width = config->width;
	screen->buffer.height = config->height;
	screen->width = config->width;
	screen->height = config->height;
	screen->loop = config->loop;
}

void	ft_screen_hook(t_screen *screen, t_screen_hook hook)
{
	mlx_hook(screen->win, hook.event, hook.mask, (int (*)()) hook.func, hook.param);
}

void			ft_screen_x_hook(t_screen *screen, t_loop_hook hook)
{
	mlx_hook(screen->win, 17, 0, hook.func, hook.param);
}

static int	ft_render_loop(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	screen->loop.func(screen->loop.param);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->buffer.img, 0, 0);
	return (0);
}

void	ft_screen_start(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, (int (*)()) ft_render_loop, screen);
	mlx_loop(screen->mlx);
}

void	ft_screen_put_pixel(t_screen *screen, int x, int y, int color)
{
	ft_screen_texture_put_pixel(&screen->buffer, x, y, color);
}
