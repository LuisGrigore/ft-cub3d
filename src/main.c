/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 15:04:47 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:28:51 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx_instance.h"
#include "config/key_code_config.h"
#include <stdlib.h>
#include <stdio.h>

void end(void *param)
{
	(void)param;
	exit(0);
}

int loop(void *param)
{
	(void)param;
	mlx_instance_clear_image_buffer(999999999);
	mlx_instance_draw_image_buffer();
	return (0);
}

int main(int argc, char const *argv[])
{
	mlx_instance_init(800, 600, "Test Window");
	mlx_instance_add_key_binding(ESC, end, NULL);
	mlx_instance_set_loop_hook(loop, NULL);
	mlx_instance_start_loop();
	mlx_instance_clear_image_buffer(0);
	
	mlx_instance_destroy();
	return 0;
}
