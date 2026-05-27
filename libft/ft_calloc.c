/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:09:27 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/01 21:08:10 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			total;
	size_t			i;

	i = 0;
	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
		return (NULL);
	arr = (unsigned char *)malloc(total);
	if (!arr)
		return (NULL);
	while (i < total)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *) arr);
}
