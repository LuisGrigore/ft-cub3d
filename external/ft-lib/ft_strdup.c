/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:02:46 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 21:27:44 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	new_str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!new_str)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	return (new_str);
}
