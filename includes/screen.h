/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 21:18:12 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/14 18:29:27 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

typedef int		(*t_key_hook_func)(int keycode, void *param);
typedef int		(*t_hook_func)(void *param);

typedef struct s_hook
{
	t_hook_func	func;
	void		*param;
}				t_hook;

typedef struct s_key_hook
{
	int			event;
	int			mask;
	t_key_hook_func	func;
	void		*param;
}				t_key_hook;

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

	t_hook	loop;

}				t_screen;

typedef struct s_screen_config
{
	int			width;
	int			height;
	char		*title;
	t_hook	loop;
}				t_screen_config;

/* Init / Destroy */
t_screen	*ft_init_screen(t_screen_config config);
void			ft_screen_destroy(t_screen *screen);

/* Lifecycle */
void			ft_screen_hook(t_screen *screen, t_key_hook hook);
void			ft_screen_x_hook(t_screen *screen, t_hook hook);
int			ft_screen_start(t_screen *screen);
int			ft_screen_stop(t_screen *screen);
void			ft_screen_put_pixel(t_screen *screen, int x, int y, int color);

/* Texture Management */
t_texture		*ft_screen_texture_load(t_screen *screen, const char *path);
void			ft_screen_texture_destroy(t_screen *screen, t_texture *tex);

int				ft_screen_texture_get_pixel(t_texture *tex, int x, int y);
void			ft_screen_texture_put_pixel(t_texture *tex, int x, int y,
					int color);

#endif
