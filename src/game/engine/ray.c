/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:40:59 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 15:09:32 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"
// #include "../../../includes/player.h"
// #include "../../../includes/parseo.h"

void	ft_init_ray(t_ray *r, t_engine *g, float angle)
{
	r->dir_x = cos(angle);
	r->dir_y = sin(angle);
	r->map_x = g->player.x / BLOCK;
	r->map_y = g->player.y / BLOCK;
	r->delta_dist_x = fabs(1 / r->dir_x);
	r->delta_dist_y = fabs(1 / r->dir_y);
	r->hit = 0;
}

void	ft_calc_step(t_ray *r, t_engine *g)
{
	if (r->dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (g->player.x / BLOCK - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1 - g->player.x / BLOCK) * r->delta_dist_x;
	}
	if (r->dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (g->player.y / BLOCK - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1 - g->player.y / BLOCK) * r->delta_dist_y;
	}
}

void	ft_perform_dda(t_ray *r, t_engine *g)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (g->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	ft_draw_wall(t_engine *g, t_ray *r, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = 0;
	while (y < r->draw_start)
		ft_screen_put_pixel(&g->screen, x, y++, g->colorC);
	while (y < r->draw_end)
	{
		tex_y = (y - r->draw_start) * r->tex->height / r->line_height;
		color = ft_screen_texture_get_pixel(r->tex, r->tex_x, tex_y);
		ft_screen_put_pixel(&g->screen, x, y, color);
		y++;
	}
	while (y < g->screen.height)
		ft_screen_put_pixel(&g->screen, x, y++, g->colorF);
}
