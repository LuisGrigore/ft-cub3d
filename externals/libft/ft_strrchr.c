/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:44:42 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 15:36:13 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	u;

	u = (char) c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == u)
			return ((char *) &s[i]);
		i--;
	}
	if (u == 0)
		return ((char *) &s[i]);
	return (NULL);
}
/* 
int main()
{
	char s[10] = "akdtkaed";
	char a = 't' + 256;
	printf("Mi funcion: %s", ft_strrchr(s, 't' + 256));
	printf("Funcion original: %s", strrchr(s,'t' + 256));
}  */
