/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:42:01 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 13:06:24 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mem;
	unsigned char	*mem2;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	mem = (unsigned char *) dest;
	mem2 = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		mem[i] = mem2[i];
		i++;
	}
	return ((void *) &mem[0]);
}
/*
int	main()
{
	char	uno[10] = "";
	char	*dos = "h";

	printf("Este es el valor de mi función: %s\n", 
			(char *)ft_memcpy(uno, dos, 5));
	printf("Este es el valor de la original: %s\n", (char *)memcpy(uno, dos, 5));
}*/
