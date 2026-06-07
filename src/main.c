/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/07 21:01:25 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parseo.h"
#include "../includes/game.h"
#include "../includes/player.h"
#include "../includes/config.h"
#include "../includes/screen.h"

int	main(void)
{
	t_game			*game;
	t_final_parse	*final;

	game = ft_calloc(1, sizeof(t_game));
	final = ft_parse();
	if (!final)
		return (printf("Error parse\n"), 1);

	ft_init_game(game, final);
	ft_start_game(game);

	ft_free_final_parse(&final);
	return (0);
}
