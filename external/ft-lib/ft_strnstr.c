/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:12:02 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 12:18:12 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TO DO: arreglar esto
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[j] && j < len)
	{
		i = 0;
		while ((j + i) < len && big[j + i] && little[i] && big[j
			+ i] == little[i])
		{
			i++;
		}
		if (little[i] == '\0')
		{
			return ((char *)&big[j]);
		}
		j++;
	}
	return (NULL);
}
