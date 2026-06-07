/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:18:12 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/07 22:33:38 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

typedef int		(*t_hook_func)(int keycode, void *param);
typedef int		(*t_loop_func)(void *param);

typedef struct s_loop_hook
{
	t_loop_func	func;
	void		*param;
}				t_loop_hook;

typedef struct s_screeen_hook
{
	int			event;
	int			mask;
	t_hook_func	func;
	void		*param;
}				t_screen_hook;

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

typedef struct s_screen
{
	void		*mlx;
	void		*win;
	t_texture	buffer;

	int			width;
	int			height;

	t_loop_hook	loop;

}				t_screen;

typedef struct s_screen_config
{
	int			width;
	int			height;
	char		*title;
	t_loop_hook	loop;
}				t_screen_config;

/* Init / Destroy */
void			ft_init_screen(t_screen *screen, t_screen_config *config);
void			ft_screen_destroy(t_screen *screen);

/* Lifecycle */
void			ft_screen_hook(t_screen *screen, t_screen_hook hook);
void			ft_screen_start(t_screen *screen);
void			ft_screen_put_pixel(t_screen *screen, int x, int y, int color);

/* Texture Management */
int				ft_screen_texture_load(t_screen *screen, t_texture *tex,
					const char *path);
void			ft_screen_texture_destroy(t_screen *screen, t_texture *tex);

int				ft_screen_texture_get_pixel(t_texture *tex, int x, int y);
void			ft_screen_texture_put_pixel(t_texture *tex, int x, int y,
					int color);

#endif
