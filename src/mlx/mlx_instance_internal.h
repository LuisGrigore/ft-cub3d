/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:34:54 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 16:48:08 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INSTANCE_INTERNAL_H
# define MLX_INSTANCE_INTERNAL_H

# include "../list/list.h"
# include "mlx_instance.h"

typedef struct s_mlx_instance
{
	void		*mlx;
	void		*mlx_win;
	t_image		*image_buffer;
	t_list		*text_buffer;
	t_list		*key_functs;
}				t_mlx_instance;

t_mlx_instance	*mlx_get_instance(void);

t_image			*init_image_buffer(void);

int				key_hook(int key_code);

void			destroy_screen_text(t_screen_text *text);

#endif