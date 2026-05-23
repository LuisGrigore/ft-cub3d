/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:04:00 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/03 13:02:16 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		return (&str[i]);
	}
	return (NULL);
}
