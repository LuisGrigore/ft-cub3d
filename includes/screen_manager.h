/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:44:57 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/02 19:14:35 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_MANAGER_H
# define SCREEN_MANAGER_H

# include "../minilibx-linux/mlx.h"

typedef int			(*t_hook_func)(int keycode, void *param);
typedef void		(*t_loop_func)(void *param);

typedef struct s_loop_hook
{
	t_loop_func		func;
	void			*param;
}					t_loop_hook;

typedef enum e_screen_event
{
	SCREEN_KEY_PRESS,
	SCREEN_KEY_RELEASE,
	SCREEN_DESTROY,
}					t_screen_event;

typedef struct s_screeen_hook
{
	int				event;
	t_hook_func		func;
	t_screen_event	mask;
	void			*param;
}					t_screen_hook;

typedef struct s_screen
{
	void			*mlx;
	void			*win;
	void			*img;

	char			*data;
	int				bpp;
	int				size_line;
	int				endian;

	int				width;
	int				height;

	t_loop_hook		loop;

} t_screen;

typedef struct s_textures
{
	void	*img;
	char	*data;
	int		width;
	int		heigth;
	int		bpp;
	int		line_len;
	int		endian;
} t_textures;

typedef struct s_screen_config
{
	int				width;
	int				height;
	char			*title;
	t_loop_hook		loop;
}					t_screen_config;

#endif
