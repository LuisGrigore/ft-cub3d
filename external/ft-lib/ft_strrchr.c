/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:31:47 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 20:36:33 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_char;

	c_char = c;
	i = ft_strlen(s);
	if (c_char == 0)
	{
		return ((char *)&s[i]);
	}
	while (i >= 0)
	{
		if (s[i] == c_char)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (0);
}
