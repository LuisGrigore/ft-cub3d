/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:44:50 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/07 21:31:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "parseo.h"
# include "player.h"
# include "screen.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_player			t_player;
typedef struct s_final_parse	t_final_parse;

typedef struct s_engine
{
	t_screen		screen;
	t_player		player;
	char			**map;
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	int				colorF;
	int				colorC;
	int				block_size;
	t_final_parse	*final;

	bool			destroy_next_frame;
}				t_engine;

typedef struct s_ray
{
	float		dir_x;
	float		dir_y;
	int			map_x;
	int			map_y;
	float		side_dist_x;
	float		side_dist_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		dist;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	float		wall_x;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	t_texture	*tex;
}				t_ray;


void	ft_init_ray(t_ray *r, t_engine *g, float angle);
void	ft_calc_step(t_ray *r, t_engine *g);
void	ft_perform_dda(t_ray *r, t_engine *g);
void	ft_calc_wall(t_ray *r, t_engine *g);
void	ft_draw_wall(t_engine *g, t_ray *r, int x);

void	ft_init_engine(t_engine *g);
void	ft_start_engine(t_engine *g);
void	ft_free_engine(t_engine *g);
int		ft_close(int keycode, void *param);


#endif
