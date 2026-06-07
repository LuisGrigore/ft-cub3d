/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:44:50 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/02 18:34:36 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "parseo.h"
# include "player.h"
# include "config.h"
# include "screen_manager.h"
# include <math.h>


typedef struct s_player t_player;
typedef struct s_final_parse t_final_parse;

typedef struct s_game
{
	t_screen	screen;
	t_player	player;
	char		**map;

	t_textures	no;
	t_textures	so;
	t_textures	we;
	t_textures	ea;

	int			colorF;
	int			colorC;

}	t_game;

typedef struct s_ray
{
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	dist;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	float	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	t_textures	*tex;
}	t_ray;

void	ft_init_game(t_game *g, t_final_parse *p);
void	ft_start_game(t_game *g);
//void	ft_render(void *param);

#endif
