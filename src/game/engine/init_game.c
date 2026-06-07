/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:00:06 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/07 21:04:22 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/game.h"
#include "../../../includes/player.h"
#include "../../../includes/screen.h"

static void	ft_load_texture(t_game *g, t_textures *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(g->screen.mlx, path,
			&tex->width, &tex->heigth);
	tex->data = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_len, &tex->endian);
}

void	ft_init_game(t_game *g, t_final_parse *p)
{
	ft_init_screen(&g->screen);
	ft_init_player(&g->player, p->f_player);
	g->colorC = p->colorC;
	g->colorF = p->colorF;
	g->map = p->grid->map;
	ft_load_texture(g, &g->no, p->text_no);
	ft_load_texture(g, &g->so, p->text_so);
	ft_load_texture(g, &g->we, p->text_we);
	ft_load_texture(g, &g->ea, p->text_ea);
}
