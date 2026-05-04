/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_text_buffer.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:04:11 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 16:46:40 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INSTANCE_TEXT_BUFFER_H
# define MLX_INSTANCE_TEXT_BUFFER_H

# include "../../vector2/vector2.h"

typedef struct s_screen_text
{
	char		*text;
	t_vector2	position;
	int			color;
}				t_screen_text;

void			mlx_instance_add_text_to_buffer(char *text, t_vector2 position,
					int color);
void			mlx_instance_clear_text_buffer(void);
void			mlx_instance_draw_text_buffer(void);

#endif