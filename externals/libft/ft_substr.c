/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goramos- <goramos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:01:11 by juan-her          #+#    #+#             */
/*   Updated: 2026/02/04 01:51:23 by goramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	lens;
	size_t	count;

	lens = ft_strlen(s);
	if (start >= lens)
		count = 0;
	else if (len > (lens - start))
		count = lens - start;
	else
		count = len;
	new = (char *) malloc((count + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
