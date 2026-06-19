/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:20:18 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/03 18:37:32 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	f_toupper(unsigned int i, char c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
} */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (char) f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/* 
int main()
{
	printf("%s", ft_strmapi("intento uno", *f_toupper));
	return (0);
}  */
