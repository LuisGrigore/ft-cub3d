/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/14 15:51:09 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/config.h"
#include "../includes/engine.h"
#include "../includes/parseo.h"


int	main(int argc, char **argv)
{
	t_engine	*engine;

	if (argc != 2)
		return (printf("Usage: %s <scene_path>\n", argv[0]), 1);
	engine = ft_calloc(1, sizeof(t_engine));
	if (!engine)
		return (1);
	engine->final = ft_parse(argv[1]);
	if (!engine->final)
		return (free(engine), printf("Error parse\n"), 1);
	ft_init_engine(engine);
	ft_start_engine(engine);
	return (0);
}
