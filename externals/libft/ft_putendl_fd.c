/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:23:54 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/04 19:32:17 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len + 2) * sizeof(char));
	while (!str)
		return ;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[len] = '\n';
	str[len + 1] = '\0';
	write(fd, str, (ft_strlen(str)));
	free(str);
}
