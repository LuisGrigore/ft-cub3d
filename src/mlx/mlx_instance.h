/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:26:35 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:15:15 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INSTANCE_H
# define MLX_INSTANCE_H

# include "../vector2/vector2.h"
# include "mlx_instance_hooks/mlx_instance_hooks.h"
# include "mlx_instance_image/mlx_instance_image.h"
# include "mlx_instance_image_buffer/mlx_instance_image_buffer.h"
# include "mlx_instance_text_buffer/mlx_instance_text_buffer.h"

int		mlx_instance_init(int width, int height, char *title);
void	mlx_instance_destroy(void);
void	mlx_instance_start_loop(void);

#endif
