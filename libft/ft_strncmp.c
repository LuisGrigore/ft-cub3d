/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:44:55 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 12:52:35 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*  
int	main()
{
	char	uno[10] = "a";
	char	*dos = " adi";
	char	uno1[10] = "a";
	char	*dos1 = " adi";
	int u1 = (int)ft_strncmp("t", "", 0);
	int u2 = (int)strncmp("t", "", 0);

	printf("Este es el valor de mi función: %i\n", u1);
	printf("La cadena resultante de mi función: %s\n", uno);
	printf("Este es el valor de la original: %i\n", u2);
	printf("La cadena resultante original: %s\n", uno1);
}  */
