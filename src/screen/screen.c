/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:01:52 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/07 21:04:01 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/screen.h"
#include "../../includes/config.h"

void	ft_init_screen(t_screen *screen)
{
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, WIDTH, HEIGHT, "cub3d");
	screen->img = mlx_new_image(screen->mlx, WIDTH, HEIGHT);
	screen->data = mlx_get_data_addr(screen->img,
			&screen->bpp, &screen->size_line, &screen->endian);
	screen->width = WIDTH;
	screen->height = HEIGHT;
}