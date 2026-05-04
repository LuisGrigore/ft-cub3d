/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_instance_hooks.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:37:06 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 16:47:56 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_INSTANCE_HOOKS_H
# define MLX_INSTANCE_HOOKS_H

typedef struct s_key_binding
{
	int		key_code;
	int		(*func)(void *param);
	void	*param;
}			t_key_binding;

void		mlx_instance_set_loop_hook(int (*loop_funct)(), void *param);
void		mlx_instance_set_x_hook(int (*loop_funct)(), void *param);
void		mlx_instance_add_key_binding(int key_code, int (*func)(),
				void *param);

#endif