/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_manager.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:44:57 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/23 17:27:43 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_MANAGER_H
# define SCREEN_MANAGER_H

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