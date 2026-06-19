/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:41:31 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 11:55:38 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		arr[i] = c;
		i++;
	}
	return ((void *)arr);
}
