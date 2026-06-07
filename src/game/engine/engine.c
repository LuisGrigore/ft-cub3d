/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:02:00 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/07 22:38:57 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"
#include "../../../includes/player.h"
#include "../../../includes/config.h"

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
		ft_screen_put_pixel(&g->screen, x, y++, g->colorC);
	while (y < r->draw_end)
	{
		int tex_y = (y - r->draw_start) * r->tex->height / r->line_height;
		int color = ft_screen_texture_get_pixel(r->tex, r->tex_x, tex_y);
		ft_screen_put_pixel(&g->screen, x, y, color);
		y++;
	}
	while (y < g->screen.height)
		ft_screen_put_pixel(&g->screen, x, y++, g->colorF);
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

static int	ft_update(void *game_ptr)
{
	t_game	*game;
	float	fov;
	float	angle;
	float	step;
	int		i;

	game = game_ptr;
	ft_move_player(&game->player, game);
	fov = PI / 3;
	angle = game->player.angle - fov / 2;
	step = fov / WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		ft_draw_line(game, angle, i);
		angle += step;
		i++;
	}
	return (0);
}

int ft_close(int keycode, void *param)
{
	(void)keycode;
	t_game *g = (t_game *)param;
	ft_screen_destroy(&g->screen);
	exit(0);
	return (0);
}

void	ft_start_game(t_game *g)
{
	ft_screen_start(&g->screen);
}

static void	ft_load_texture(t_game *g, t_texture *tex, char *path)
{
	if (ft_screen_texture_load(&g->screen, tex, path) != 0)
	{
		/* TODO: manejar error apropiadamente */
	}
}

void	ft_init_game(t_game *g, t_final_parse *p)
{
	ft_init_screen(&g->screen, &(t_screen_config){
		.width = WIDTH,
		.height = HEIGHT,
		.title = "Cub3D",
		.loop = (t_loop_hook){.func = ft_update, .param = g}
	});
	ft_screen_hook(&g->screen, (t_screen_hook){17, 0, ft_close, g});
	ft_screen_hook(&g->screen, (t_screen_hook){2, 1L << 0, ft_player_key_press, &g->player});
	ft_screen_hook(&g->screen, (t_screen_hook){3, 1L << 1, ft_player_key_release, &g->player});
	ft_init_player(&g->player, p->f_player);
	g->colorC = p->colorC;
	g->colorF = p->colorF;
	g->map = p->grid->map;
	ft_load_texture(g, &g->no, p->text_no);
	ft_load_texture(g, &g->so, p->text_so);
	ft_load_texture(g, &g->we, p->text_we);
	ft_load_texture(g, &g->ea, p->text_ea);
}
