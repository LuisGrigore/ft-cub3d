/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:01:52 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 14:33:28 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../includes/screen.h"
#include <stdlib.h>

t_screen	*ft_init_screen(t_screen_config config)
{
	t_screen	*screen;

	screen = (t_screen *)malloc(sizeof(t_screen));
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, config.width, config.height,
			config.title);
	screen->buffer.img = mlx_new_image(screen->mlx, config.width,
			config.height);
	screen->buffer.data = mlx_get_data_addr(screen->buffer.img,
			&screen->buffer.bpp, &screen->buffer.line_len,
			&screen->buffer.endian);
	screen->buffer.width = config.width;
	screen->buffer.height = config.height;
	screen->width = config.width;
	screen->height = config.height;
	screen->loop = config.loop;
	return screen;
}

void	ft_screen_hook(t_screen *screen, t_key_hook hook)
{
	mlx_hook(screen->win, hook.event, hook.mask, (int (*)()) hook.func, hook.param);
}

void			ft_screen_x_hook(t_screen *screen, t_hook hook)
{
	mlx_hook(screen->win, 17, 0, (int (*)()) hook.func, hook.param);
}

static int	ft_render_loop(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	screen->loop.func(screen->loop.param);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->buffer.img, 0, 0);
	return (0);
}

int	ft_screen_start(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, (int (*)()) ft_render_loop, screen);
	return mlx_loop(screen->mlx);
}

int ft_screen_stop(t_screen *screen)
{
	return mlx_loop_end(screen->mlx);
}

void	ft_screen_destroy(t_screen *screen)
{
	if (!screen)
		return ;
	if (screen->buffer.img)
		mlx_destroy_image(screen->mlx, screen->buffer.img);
	if (screen->win)
		mlx_destroy_window(screen->mlx, screen->win);
	if (screen->mlx)
	{
		mlx_destroy_display(screen->mlx);
		free(screen->mlx);
	}
	screen->mlx = NULL;
	screen->win = NULL;
	free(screen);
}

void	ft_screen_put_pixel(t_screen *screen, int x, int y, int color)
{
	ft_screen_texture_put_pixel(&screen->buffer, x, y, color);
}
