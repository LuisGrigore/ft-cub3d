/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:34:30 by juan-her          #+#    #+#             */
/*   Updated: 2026/02/17 15:39:21 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;
	size_t	total;
	char	*join;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	total = len_s1 + len_s2 + 1;
	join = (char *) malloc(total * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (len_s1 + len_s2))
	{
		if (i < len_s1)
			join[i] = s1[i];
		else
			join[i] = s2[i - len_s1];
		i++;
	}
	join[i] = '\0';
	return (join);
}
/* int main()
{
	printf ("%s", ft_join(" hola ", "adios"));
	return (0);
} */
