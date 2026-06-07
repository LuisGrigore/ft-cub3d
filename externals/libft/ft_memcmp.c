/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:46:07 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 13:07:52 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem;
	unsigned char	*mem2;
	size_t			i;

	mem = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (mem[i] != mem2[i])
			return (mem[i] - mem2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (mem[i] - mem2[i]);
}
/* 
int	main(void)
{
	char	uno[10] = "";
	char	*dos = "";

	printf("mi función: %d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	printf("la original: %d\n", memcmp("abcdefghij", "abcdefgxyz", 7));
	return 0;
	
} */
