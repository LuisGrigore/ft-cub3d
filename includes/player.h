/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:43:34 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/12 20:18:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <stdbool.h>

typedef struct s_engine	t_engine;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}						t_player;

typedef struct player_config
{
	float	starting_x;
	float	starting_y;
	float	starting_angle;

}						t_player_config;

void	ft_init_player(t_player *player,
							t_player_config config);
int		ft_player_key_press(int keycode, void *player_ptr);
int		ft_player_key_release(int keycode, void *player_ptr);
void	ft_move_player(t_player *p, t_engine *g);
#endif
