/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_image_buffer.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:04:11 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 16:47:06 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INSTANCE_IMAGE_BUFFER_H
# define MLX_INSTANCE_IMAGE_BUFFER_H

# include "../../vector2/vector2.h"
# include "../mlx_instance_image/mlx_instance_image.h"

void	mlx_instance_add_image_to_buffer(t_image *img, t_vector2 position);
void	mlx_instance_clear_image_buffer(int color);
void	mlx_instance_draw_image_buffer(void);

#endif