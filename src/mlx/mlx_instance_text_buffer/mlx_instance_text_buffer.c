/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_text_buffer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:27:42 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:18:18 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../utils/utils.h"
#include "../mlx_instance_internal.h"
#include "mlx_instance_text_buffer.h"

void	mlx_instance_add_text_to_buffer(char *text, t_vector2 position,
		int color)
{
	t_screen_text	*screen_text;

	screen_text = ft_calloc(1, sizeof(t_screen_text));
	if (!screen_text)
		return ;
	screen_text->text = ft_strdup(text);
	screen_text->position = position;
	screen_text->color = color;
	insert_front(mlx_get_instance()->text_buffer, screen_text);
}

void	mlx_instance_clear_text_buffer(void)
{
	t_node	*current;
	t_node	*next;

	current = mlx_get_instance()->text_buffer->head;
	while (current)
	{
		next = current->next;
		remove_element(mlx_get_instance()->text_buffer, current->data,
			destroy_screen_text);
		current = next;
	}
}

static void	draw_screen_text(void *screen_text_ptr)
{
	t_screen_text	*screen_text;

	screen_text = (t_screen_text *)screen_text_ptr;
	mlx_string_put(mlx_get_instance()->mlx, mlx_get_instance()->mlx_win,
		screen_text->position.x, screen_text->position.y, screen_text->color,
		screen_text->text);
}

void	mlx_instance_draw_text_buffer(void)
{
	traverse_list(mlx_get_instance()->text_buffer, draw_screen_text);
}

void	destroy_screen_text(t_screen_text *text)
{
	if (text->text)
		free(text->text);
	free(text);
}
