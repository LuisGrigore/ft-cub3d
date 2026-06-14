/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:52:34 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/12 22:51:14 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../includes/screen.h"
#include <stdlib.h>

int	ft_screen_texture_load(t_screen *screen, t_texture *tex, const char *path)
{
	extern void	*mlx_xpm_file_to_image(void *, char *, int *, int *);
	extern char	*mlx_get_data_addr(void *, int *, int *, int *);

	tex->img = mlx_xpm_file_to_image(screen->mlx, (char *)path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (-1);
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	return (0);
}

int	ft_screen_texture_get_pixel(t_texture *tex, int x, int y)
{
	int	i;

	i = y * tex->line_len + x * (tex->bpp / 8);
	return (*(int *)(tex->data + i));
}

void	ft_screen_texture_put_pixel(t_texture *tex, int x, int y, int color)
{
	int	i;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return ;
	i = y * tex->line_len + x * (tex->bpp / 8);
	tex->data[i] = color & 0xFF;
	tex->data[i + 1] = (color >> 8) & 0xFF;
	tex->data[i + 2] = (color >> 16) & 0xFF;
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
