/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_hooks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:01 by lgrigore          #+#    #+#             */
/*   Updated: 2026/05/04 15:17:20 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../externals/minilibx-linux/mlx.h"
#include "../../list/list.h"
#include "../../utils/utils.h"
#include "../mlx_instance_internal.h"
#include "mlx_instance_hooks.h"
#include <stdio.h>

void	mlx_instance_set_loop_hook(int (*loop_funct)(), void *param)
{
	mlx_loop_hook(mlx_get_instance()->mlx, loop_funct, param);
}

void	mlx_instance_set_x_hook(int (*loop_funct)(), void *param)
{
	mlx_hook(mlx_get_instance()->mlx_win, 17, 0L, loop_funct, param);
}

void	mlx_instance_add_key_binding(int key_code, int (*func)(), void *param)
{
	t_key_binding	*key_binding;

	key_binding = ft_calloc(1, sizeof(t_key_binding));
	if (!key_binding)
		return ;
	key_binding->key_code = key_code;
	key_binding->func = func;
	key_binding->param = param;
	insert_front(mlx_get_instance()->key_functs, key_binding);
}

int	key_hook(int key_code)
{
	t_node *current;
	t_key_binding *key_binding;

	current = mlx_get_instance()->key_functs->head;
	while (current)
	{
		key_binding = (t_key_binding *)current->data;
		if (key_binding->key_code == key_code)
		{
			key_binding->func(key_binding->param);
			break ;
		}
		current = current->next;
	}
}