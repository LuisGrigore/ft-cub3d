/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 17:29:47 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:18:06 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/minilibx-linux/mlx.h"
#include "../../utils/utils.h"
#include "../mlx_instance.h"
#include "../mlx_instance_internal.h"
#include <stdlib.h>

t_image	*init_image(void *img, char *addr, int bpp, int line_length, int endian,
		int width, int height)
{
	t_image	*new_image;

	new_image = ft_calloc(1, sizeof(t_image));
	if (!new_image)
		return (NULL);
	new_image->addr = addr;
	new_image->bpp = bpp;
	new_image->endian = endian;
	new_image->height = height;
	new_image->width = width;
	new_image->img = img;
	new_image->line_length = line_length;
	return (new_image);
}

t_image	*mlx_instance_load_image(char *xpm_path)
{
	void	*img;
	char	*addr;
	t_image	*image;
	void	*mlx;

	int bpp, line_length, endian;
	int width, height;
	mlx = mlx_get_instance()->mlx;
	img = mlx_xpm_file_to_image(mlx, xpm_path, &width, &height);
	if (!img)
		return (NULL);
	addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
	if (!addr)
	{
		mlx_destroy_image(mlx, img);
		return (NULL);
	}
	image = init_image(img, addr, bpp, line_length, endian, width, height);
	if (!image)
	{
		mlx_destroy_image(mlx, img);
		return (NULL);
	}
	return (image);
}
void	mlx_instance_unload_image(t_image *image)
{
	if (!image)
		return ;
	if (image->img)
	{
		mlx_destroy_image(mlx_get_instance()->mlx, image->img);
		free(image);
	}
}