/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:39:38 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/02 11:55:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 47 && c < 58) || (c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>

int	main ()
{
	char	uno = '9';

	printf("Este es el valor de mi función: %i \n", ft_isalnum(uno));
	printf("Este es el valor de la original: %i", isalnum(uno));
}*/
