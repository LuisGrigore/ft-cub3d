/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:32:09 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/12 13:55:50 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchr(const char *str, int n)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp != (char)n)
	{
		if (*tmp == 0)
			return (NULL);
		tmp++;
	}
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!s)
		return (NULL);
	srclen = ft_strlen(s);
	if (start > srclen)
		return (NULL);
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr_with_nline(char *str, int out)
{
	if (!str)
		return ;
	write(out, str, ft_strlen(str));
	write(out, "\n", 1);
}
