/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:37:46 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 17:31:26 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/config.h"
#include "../../includes/engine.h"


void	ft_free_final_parse(t_final_parse **final)
{
	int	i;

	if (!final || !*final)
		return ;
	if ((*final)->grid)
	{
		if ((*final)->grid->map)
		{
			i = 0;
			while ((*final)->grid->map[i])
				free((*final)->grid->map[i++]);
			free((*final)->grid->map);
		}
		free((*final)->grid);
	}
	free((*final)->text_no);
	free((*final)->text_so);
	free((*final)->text_we);
	free((*final)->text_ea);
	free((*final)->color_f);
	free((*final)->color_c);
	free(*final);
	*final = NULL;
}

int	ft_close(int keycode, void *param)
{
	t_engine	*g;

	(void)keycode;
	g = (t_engine *)param;
	ft_free_engine(g);
	free(g);
	g = NULL;
	return (0);
}

void	ft_free_engine(t_engine *g)
{
	if (!g)
		return ;
	ft_screen_texture_destroy(&g->screen, &g->no);
	ft_screen_texture_destroy(&g->screen, &g->so);
	ft_screen_texture_destroy(&g->screen, &g->we);
	ft_screen_texture_destroy(&g->screen, &g->ea);
	if (g->final)
		ft_free_final_parse(&g->final);
	ft_screen_destroy(&g->screen);
}
