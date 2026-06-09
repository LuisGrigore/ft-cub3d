/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:13 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/09 16:17:10 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"
#include "../includes/parseo.h"
#include "../includes/player.h"
#include "../includes/screen.h"

int	main(void)
{
	t_engine		engine;
	t_final_parse	*final;

	final = ft_parse();
	if (!final)
		return (printf("Error parse\n"), 1);
	ft_init_engine(&engine, final);
	
	ft_start_engine(&engine);
	ft_free_final_parse(&final);
	return (0);
}
