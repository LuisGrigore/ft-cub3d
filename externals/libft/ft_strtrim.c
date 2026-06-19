/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:46:14 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/05 15:45:28 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while ((end > start) && s1[start] && ft_strchr(set, s1[end - 1]))
		end--;
	new = ft_substr(s1, start, end - start);
	return (new);
}
/* 
int	main(void)
{
	char	*s1 = "iiidaeefs";
	char	*set = "da";

	printf("%s", ft_strtrim(s1, set));
	return (0);
} */
