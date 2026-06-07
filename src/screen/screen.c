/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:01:52 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/07 22:31:20 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../externals/minilibx-linux/mlx.h"
#include <stdlib.h>

void	ft_init_screen(t_screen *screen, t_screen_config *config)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, config->width, config->height, config->title);
	screen->buffer.img = mlx_new_image(screen->mlx, config->width, config->height);
	screen->buffer.data = mlx_get_data_addr(screen->buffer.img,
			&screen->buffer.bpp, &screen->buffer.line_len, &screen->buffer.endian);
	screen->buffer.width = config->width;
	screen->buffer.height = config->height;
	screen->width = config->width;
	screen->height = config->height;
	screen->loop = config->loop;
}


void	ft_screen_destroy(t_screen *screen)
{
	if (screen->win)
		mlx_destroy_window(screen->mlx, screen->win);
}

void	ft_screen_hook(t_screen *screen, t_screen_hook hook)
{
	mlx_hook(screen->win, hook.event, hook.mask, hook.func, hook.param);
}


static int ft_render_loop(void *param)
{
	t_screen *screen = (t_screen *)param;
	screen->loop.func(screen->loop.param);
	mlx_put_image_to_window(screen->mlx, screen->win, screen->buffer.img, 0, 0);
	return (0);
} 

void	ft_screen_start(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, ft_render_loop, screen);
	mlx_loop(screen->mlx);
}



int	ft_screen_texture_load(t_screen *screen, t_texture *tex, const char *path)
{
	extern void	*mlx_xpm_file_to_image(void *, char *, int *, int *);
	extern char	*mlx_get_data_addr(void *, int *, int *, int *);

	tex->img = mlx_xpm_file_to_image(screen->mlx, (char *)path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (-1);
	tex->data = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
	return (0);
}

void	ft_screen_texture_destroy(t_screen *screen, t_texture *tex)
{
	if (!tex)
		return ;
	if (tex->img)
		mlx_destroy_image(screen->mlx, tex->img);
	tex->img = NULL;
	tex->data = NULL;
}
int	ft_screen_texture_get_pixel(t_texture *tex, int x, int y)
{
	int i;

	i = y * tex->line_len + x * (tex->bpp / 8);
	return (*(int *)(tex->data + i));
}

void	ft_screen_texture_put_pixel(t_texture *tex, int x, int y, int color)
{
	int i;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return ;
	i = y * tex->line_len + x * (tex->bpp / 8);
	tex->data[i] = color & 0xFF;
	tex->data[i + 1] = (color >> 8) & 0xFF;
	tex->data[i + 2] = (color >> 16) & 0xFF;
}
void ft_screen_put_pixel(t_screen *screen, int x, int y, int color)
{
	ft_screen_texture_put_pixel(&screen->buffer, x, y, color);
}
