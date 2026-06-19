/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 22:15:38 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/19 16:19:17 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"
# include <math.h>

static t_texture	*ft_side_x(t_ray *r, t_engine *g)
{
	if (r->dir_x > 0)
		return (g->ea);
	else
		return (g->we);
}

static t_texture	*ft_side_y(t_ray *r, t_engine *g)
{
	if (r->dir_y > 0)
		return (g->so);
	else
		return (g->no);
}

void    ft_calc_wall(t_ray *r, t_engine *g)
{
    if (r->side == 0)
        r->dist = (r->map_x - g->player.x / BLOCK + (1 - r->step_x) / 2)
            / r->dir_x;
    else
        r->dist = (r->map_y - g->player.y / BLOCK + (1 - r->step_y) / 2)
            / r->dir_y;
    r->dist *= BLOCK;
    r->line_height = g->screen->height / r->dist * BLOCK;
    r->draw_start = -r->line_height / 2 + g->screen->height / 2;
    r->draw_start_real = r->draw_start;
    if (r->draw_start < 0)
        r->draw_start = 0;
    r->draw_end = r->line_height / 2 + g->screen->height / 2;
    if (r->draw_end >= g->screen->height)
        r->draw_end = g->screen->height - 1;
    if (r->side == 0)
        r->tex = ft_side_x(r, g);
    else
        r->tex = ft_side_y(r, g);
    if (r->side == 0)
        r->wall_x = g->player.y / BLOCK + r->dist / BLOCK * r->dir_y;
    else
        r->wall_x = g->player.x / BLOCK + r->dist / BLOCK * r->dir_x;
    r->wall_x -= floor(r->wall_x);
    r->tex_x = r->wall_x * r->tex->width;
}
