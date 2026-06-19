/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:52:34 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/19 21:14:46 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../includes/screen.h"
#include <stdlib.h>

t_texture	*ft_screen_texture_load(t_screen *screen, const char *path)
{
	t_texture	*tex;

	tex = (t_texture *)malloc(sizeof(t_texture));
	if (!tex)
		return (NULL);
	tex->img = mlx_xpm_file_to_image(screen->mlx, (char *)path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (ft_screen_texture_destroy(screen, tex), NULL);
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	return (tex);
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

void	ft_screen_texture_destroy(t_screen *screen, t_texture *tex)
{
	if (!tex)
		return ;
	if (tex->img)
		mlx_destroy_image(screen->mlx, tex->img);
	tex->img = NULL;
	tex->data = NULL;
	free(tex);
}
