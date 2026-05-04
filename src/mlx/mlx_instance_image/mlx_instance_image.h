/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_image.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:01:10 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 15:04:57 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INSTANCE_IMAGE_H
# define MLX_INSTANCE_IMAGE_H

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

t_image		*init_image(void *img, char *addr, int bpp, int line_length,
				int endian, int width, int height);
t_image		*mlx_instance_load_image(char *xpm_path);
void		mlx_instance_unload_image(t_image *image);

#endif