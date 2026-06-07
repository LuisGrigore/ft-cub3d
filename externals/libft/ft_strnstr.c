/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:46:27 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 16:46:09 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenl;

	i = 0;
	if (!*little)
		return ((char *) big);
	lenl = ft_strlen(little);
	if (!*big)
		return (NULL);
	if (lenl > len)
		return (NULL);
	while (i + lenl <= len)
	{
		j = 0;
		while (j < lenl && big[i + j] == little[j])
			j++;
		if (j == lenl)
			return ((char *) &big[i]);
		if (big[i] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}
/*  int main()
{
	char big[1024] = "hola felipe, cabron!!";
	char *lit = "MZIRIBMZE";
	char big1[1024] = "hola felipe, cabron!!";
	char *lit1 = "hola";
	size_t max = ft_strlen(lit);
	//char *b = (char *) strnstr(big1, lit1, max);
	char *str = ft_strnstr("MZIRIBMZIRIBMZE123", lit, max);
	printf("Mi funcion: %s", str);
	//printf("Mi funcion: %s", b);
	return 0;
}  */
