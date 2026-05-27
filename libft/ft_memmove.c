/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:42:15 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 18:02:49 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (n <= 0)
		return (dest);
	if ((unsigned char *)dest < (unsigned char *)src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i ++;
		}
		return (dest);
	}
	i = n;
	while (-- i > 0)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (((unsigned char *)dest)[i] = ((unsigned char *)src)[i], dest);
}
/* int	main()
{
	char	dos[23] = "hello mister i am dead";
	char	*uno = &(dos[1]); //"ello mister i am dead";

	printf("mi función: %s\n", (char *) ft_memmove(dos, uno, 6));

	char	cuatro[23] = "hello mister i am dead";
	char	*tres = &(cuatro[1]); //"ello mister i am dead";

	printf("original: %s\n", (char *) memmove(cuatro, tres, 6));
} */
