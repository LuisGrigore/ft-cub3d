/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:23:02 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/27 20:55:11 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen_manager.h"
#include <stdbool.h>
#include <stdlib.h>

void	init_screen(t_screen *screen, t_screen_config config)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, config.width, config.height,
			config.title);
	screen->img = mlx_new_image(screen->mlx, config.width, config.height);
	screen->data = mlx_get_data_addr(screen->img, &screen->bpp,
			&screen->size_line, &screen->endian);
	screen->width = config.width;
	screen->height = config.height;
	screen->loop = config.loop;
	mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
}

static int	screen_draw_loop_hook(void *param)
{
	t_screen	*screen;

	screen = (t_screen *)param;
	if (screen && screen->loop.func)
		screen->loop.func(screen->loop.param);
	if (screen)
		mlx_put_image_to_window(screen->mlx, screen->win, screen->img, 0, 0);
	return (0);
}

void	start_screen(t_screen *screen)
{
	//mlx_loop_hook(screen->mlx, screen_draw_loop_hook, screen); Cambiado no se si para el cluster de igual
	mlx_loop_hook(screen->mlx, (int (*)())screen_draw_loop_hook, screen);
	mlx_loop(screen->mlx);
}

void	put_pixel(int x, int y, int color, t_screen *screen)
{
	int	index;

	if (x >= screen->width || y >= screen->height || x < 0 || y < 0)
		return ;
	index = y * screen->size_line + x * screen->bpp / 8;
	screen->data[index] = color & 0xFF;
	screen->data[index + 1] = (color >> 8) & 0xFF;
	screen->data[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_screen *screen)
{
	int	y;
	int	x;

	if (!screen || !screen->data)
		return ;
	y = 0;
	while (y < screen->height)
	{
		x = 0;
		while (x < screen->width)
		{
			put_pixel(x, y, 0, screen);
			x++;
		}
		y++;
	}
}
void	set_hook(t_screen *screen, t_screen_hook hook)
{
	int	mask;
	int	event;

	if (hook.event == SCREEN_KEY_PRESS)
	{
		event = 2;
		mask = 1L << 0;
	}
	else if (hook.event == SCREEN_KEY_RELEASE)
	{
		event = 3;
		mask = 1L << 1;
	}
	else if (hook.event == SCREEN_DESTROY)
	{
		event = 17;
		mask = 0;
	}
	else
		return ;
	//mlx_hook(screen->win, event, mask, hook.func, hook.param); Tmbien usado porque son funciones decrepitas
	mlx_hook(screen->win, event, mask, (int (*)())hook.func, hook.param);
}
