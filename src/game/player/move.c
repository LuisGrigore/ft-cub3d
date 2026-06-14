/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:57:44 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 15:51:32 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/config.h"
#include "../../../includes/engine.h"

static int	touch(float x, float y, t_engine *g)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK);
	map_y = (int)(y / BLOCK);
	if (!g->map || !g->map[map_y])
		return (1);
	return (g->map[map_y][map_x] == '1');
}

static void	ft_move_2(t_player *p, t_engine *g, float speed)
{
	float	nx;
	float	ny;

	if (p->key_left)
	{
		nx = p->x - sin(p->angle) * speed;
		ny = p->y + cos(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->key_right)
	{
		nx = p->x + sin(p->angle) * speed;
		ny = p->y - cos(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->left_rotate)
		p->angle -= 0.03;
	if (p->right_rotate)
		p->angle += 0.03;
}

void	ft_move_player(t_player *p, t_engine *g)
{
	float	speed;
	float	nx;
	float	ny;

	speed = 3;
	if (p->key_up)
	{
		nx = p->x + cos(p->angle) * speed;
		ny = p->y + sin(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	if (p->key_down)
	{
		nx = p->x - cos(p->angle) * speed;
		ny = p->y - sin(p->angle) * speed;
		if (!touch(nx, p->y, g))
			p->x = nx;
		if (!touch(p->x, ny, g))
			p->y = ny;
	}
	ft_move_2(p, g, speed);
}
