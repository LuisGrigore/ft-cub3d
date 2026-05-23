/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:21:18 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/06 09:40:05 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checks(char const *s, unsigned int start, size_t len)
{
	if (!s)
	{
		return (-1);
	}
	if (start > ft_strlen(s))
	{
		return (0);
	}
	if (len > ft_strlen(s) - start)
	{
		return (ft_strlen(s) - start);
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (checks(s, start, len) == -1)
	{
		return (NULL);
	}
	else
	{
		len = checks(s, start, len);
	}
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
