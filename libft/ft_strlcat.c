/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:43:40 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 00:13:16 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	length;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (size > d)
		length = s + d;
	else
		length = s + size;
	while (src[i] && size > (d + 1))
	{
		dst[d] = src[i];
		i++;
		d++;
	}
	dst[d] = '\0';
	return (length);
}
/*
int	main()
{
	char	uno[10] = "hola";
	char	*dos = " adi";
	char	uno1[10] = "hola";
	char	*dos1 = " adi";
	int u1 = (int)ft_strlcat(uno, dos, 4);
	int u2 = (int)strlcat(uno1, dos1, 4);

	printf("Este es el valor de mi función: %i\n", u1);
	printf("La cadena resultante de mi función: %s\n", uno);
	printf("Este es el valor de la original: %i\n", u2);
	printf("La cadena resultante original: %s\n", uno1);
}*/
