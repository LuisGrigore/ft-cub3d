/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/03 14:02:54 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"
#include "../../../includes/player.h"

static int	ft_get_pixel(t_textures *tex, int x, int y)
{
	int i; 
	i = y * tex->line_len + x * (tex->bpp / 8);
	return (*(int *)(tex->data + i));
}

static void	ft_put_pixel(t_game *g, int x, int y, int color)
{
	int i;
	i = y * g->screen.size_line + x * (g->screen.bpp / 8);
	g->screen.data[i] = color & 0xFF;
	g->screen.data[i + 1] = (color >> 8) & 0xFF;
	g->screen.data[i + 2] = (color >> 16) & 0xFF;
}

static void	ft_init_ray(t_ray *r, t_game *g, float angle)
{
	r->dir_x = cos(angle);
	r->dir_y = sin(angle);
	r->map_x = g->player.x / BLOCK;
	r->map_y = g->player.y / BLOCK;
	r->delta_dist_x = fabs(1 / r->dir_x);
	r->delta_dist_y = fabs(1 / r->dir_y);
	r->hit = 0;
}

static void	ft_calc_step(t_ray *r, t_game *g)
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

static void	ft_perform_dda(t_ray *r, t_game *g)
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

static void	ft_calc_wall(t_ray *r, t_game *g)
{
	if (r->side == 0)
		r->dist = (r->map_x - g->player.x / BLOCK + (1 - r->step_x) / 2) / r->dir_x;
	else
		r->dist = (r->map_y - g->player.y / BLOCK + (1 - r->step_y) / 2) / r->dir_y;
	r->dist *= BLOCK;
	r->line_height = g->screen.height / r->dist * BLOCK;
	r->draw_start = -r->line_height / 2 + g->screen.height / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + g->screen.height / 2;
	if (r->draw_end >= g->screen.height)
		r->draw_end = g->screen.height - 1;
	if (r->side == 0)
		r->tex = (r->dir_x > 0) ? &g->ea : &g->we;
	else
		r->tex = (r->dir_y > 0) ? &g->so : &g->no;
	if (r->side == 0)
		r->wall_x = g->player.y / BLOCK + r->dist / BLOCK * r->dir_y;
	else
		r->wall_x = g->player.x / BLOCK + r->dist / BLOCK * r->dir_x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = r->wall_x * r->tex->width;
}

static void	ft_draw_wall(t_game *g, t_ray *r, int x)
{
	int y;

	y = 0;
	while (y < r->draw_start)
		ft_put_pixel(g, x, y++, g->colorC);
	while (y < r->draw_end)
	{
		int tex_y = (y - r->draw_start) * r->tex->heigth / r->line_height;
		int color = ft_get_pixel(r->tex, r->tex_x, tex_y);
		ft_put_pixel(g, x, y, color);
		y++;
	}
	while (y < g->screen.height)
		ft_put_pixel(g, x, y++, g->colorF);
}

static void	ft_draw_line(t_game *g, float angle, int x)
{
	t_ray r;

	ft_init_ray(&r, g, angle);
	ft_calc_step(&r, g);
	ft_perform_dda(&r, g);
	ft_calc_wall(&r, g);
	ft_draw_wall(g, &r, x);
}

static int	ft_render(void *param)
{
	t_game	*g;
	float	fov;
	float	angle;
	float	step;
	int		i;

	g = param;
	ft_move_player(&g->player, g);
	fov = PI / 3;
	angle = g->player.angle - fov / 2;
	step = fov / WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		ft_draw_line(g, angle, i);
		angle += step;
		i++;
	}
	mlx_put_image_to_window(g->screen.mlx, g->screen.win, g->screen.img, 0, 0);
	return (0);
}

int ft_close(t_game *g)
{
	mlx_destroy_window(g->screen.mlx, g->screen.win);
	exit(0);
	return (0);
}

void	ft_start_game(t_game *g)
{
	mlx_hook(g->screen.win, 17, 0, (int (*)())ft_close, g);
	mlx_hook(g->screen.win, 2, 1L << 0, (int (*)())ft_player_key_press, &g->player);
    mlx_hook(g->screen.win, 3, 1L << 1, (int (*)())ft_player_key_release, &g->player);
    mlx_loop_hook(g->screen.mlx, (int (*)())ft_render, g);
    mlx_loop(g->screen.mlx);
}
