/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:45:15 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 11:54:41 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;

	mem = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return (&mem[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	uno[10] = "hola";
	char	dos = 'o';
	char	uno1[10] = "hola";
	char	dos1 = 'o';

	printf("mi función: %s\n", (char *)ft_memchr(uno, dos, 5));
	printf("la original: %s\n", (char *)memchr(uno1, dos1, 5));
}*/
