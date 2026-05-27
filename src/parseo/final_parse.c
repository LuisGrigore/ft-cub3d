/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:27:01 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/27 21:05:45 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"
#include "../../includes/player.h"

int	ft_rgb_to_int(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if(!rgb)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_split(rgb);
	return ((r << 16) | (g << 8) | b);
}

/* int	ft_load_textures(void *mlx, t_textures*tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->heigth);
	if (!tex->img)
		exit(printf("Error: Textures\n"));
	tex->dir = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len, &tex->endian);
} */

t_final_parse	*ft_final_parse(t_parseo *parse)
{
	t_final_parse	*final;

	final = malloc(sizeof(t_final_parse));
	if (!final)
		return (NULL);
	//Me falta lo del angulo
	final->grid = ft_create_grid(parse->map);
	final->colorC = ft_rgb_to_int(parse->header->color_c);
	final->colorF = ft_rgb_to_int(parse->header->color_f);
	final->f_player.starting_x = parse->player_x + 0.5;
	final->f_player.starting_y = parse->player_y + 0.5;
	final->text_no = ft_strdup(parse->header->text_no);
	final->text_ea = ft_strdup(parse->header->text_ea);
	final->text_we = ft_strdup(parse->header->text_we);
	final->text_so = ft_strdup(parse->header->text_so);
	return (final);
}

