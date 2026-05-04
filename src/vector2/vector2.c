/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:22:41 by lgrigore          #+#    #+#             */
/*   Updated: 2025/04/09 13:43:01 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector2.h"

t_vector2	get_vector(float x, float y)
{
	t_vector2	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector2	sum_vector2(t_vector2 a, t_vector2 b)
{
	t_vector2	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}
