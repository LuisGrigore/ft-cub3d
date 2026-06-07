/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:03:21 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/06 16:28:33 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countw(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static void	free_arr(char **solve)
{
	size_t	i;

	i = 0;
	while (solve[i])
	{
		free(solve[i]);
		i++;
	}
	free(solve);
}

char	**ft_split(char const *s, char c)
{
	char	**solve;
	size_t	iteration[2];
	size_t	start;

	if (!s)
		return (NULL);
	solve = (char **)malloc((ft_countw(s, c) + 1) * sizeof(char *));
	if (!solve)
		return (NULL);
	iteration[0] = 0;
	iteration[1] = 0;
	while (iteration[1] < ft_countw(s, c))
	{
		while (s[iteration[0]] && s[iteration[0]] == c)
			iteration[0]++;
		start = iteration[0];
		while (s[iteration[0]] && s[iteration[0]] != c)
			iteration[0]++;
		if (iteration[0] > start)
			solve[iteration[1]] = ft_substr(s, start, iteration[0] - start);
		if (!solve[iteration[1]])
			return (free_arr(solve), NULL);
		iteration[1]++;
	}
	return (solve[iteration[1]] = NULL, solve);
}
/*  int main (void)
{
	//free(solve);
	//solve = (char **) malloc(count * sizeof(char));
	char	**ho = ft_split("hello! aksgfda ddf d   fwe few fw ew f w!!!!", ' ');

	for(int i=0; i < 4; i++)
	{
		printf("%s\n", ho[i]);
	}
	return (0);
} */
