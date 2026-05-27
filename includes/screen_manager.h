/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:44:57 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/27 19:55:06 by juan-her         ###   ########.fr       */
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

}					t_screen;

//la puse para las hacer las texturas la funcion se encuenta en final_parse
typedef struct s_textures
{
	void	*img;
	char	*dir;
	int		width;
	int		heigth;
	int		bpp;
	int		line_len;
	int		endian;
}	t_textures;

typedef struct s_screen_config
{
	int				width;
	int				height;
	char			*title;
	t_loop_hook		loop;
}					t_screen_config;

void				init_screen(t_screen *screen, t_screen_config config);
void				start_screen(t_screen *screen);
void				set_hook(t_screen *screen, t_screen_hook hook);
void				put_pixel(int x, int y, int color, t_screen *screen);
void				clear_image(t_screen *screen);
// TODO
void				destroy_screen(t_screen *screen);
#endif
