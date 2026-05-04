/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:38:53 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/08 14:38:54 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

typedef struct s_vector2
{
	float	x;
	float	y;
}			t_vector2;

t_vector2	get_vector(float x, float y);
t_vector2	sum_vector2(t_vector2 a, t_vector2 b);

#endif