/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:15:36 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 21:07:29 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *v, int c, size_t s)
{
	unsigned char	*str;

	str = (unsigned char *)v;
	while (s--)
	{
		*str++ = (unsigned char)c;
	}
	return (v);
}
