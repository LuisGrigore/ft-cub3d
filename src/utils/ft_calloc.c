/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:47:28 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 23:33:04 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"
#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
	{
		return (NULL);
	}
	byte_ptr = (unsigned char *)ptr;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}
