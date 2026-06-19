/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:01:52 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 21:12:24 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../includes/screen.h"
#include <stdlib.h>

void	ft_screen_hook(t_screen *screen, t_key_hook hook)
{
	mlx_hook(screen->win, hook.event, hook.mask, (int (*)())hook.func,
		hook.param);
}

void	ft_screen_x_hook(t_screen *screen, t_hook hook)
{
	mlx_hook(screen->win, 17, 0, hook.func, hook.param);
}

int	ft_screen_stop(t_screen *screen)
{
	return (mlx_loop_end(screen->mlx));
}

void	ft_screen_put_pixel(t_screen *screen, int x, int y, int color)
{
	ft_screen_texture_put_pixel(&screen->buffer, x, y, color);
}
