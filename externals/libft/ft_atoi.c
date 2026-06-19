/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:46:48 by juan-her          #+#    #+#             */
/*   Updated: 2025/11/07 16:58:26 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == ' ') || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && (str[i] > 47) && (str[i] < 58))
	{
		res = (long)((res * 10) + (str[i] - '0'));
		i++;
	}
	return (res * sign);
}
/* #include <stdio.h>
#include <stdlib.h>

int	main ()
{
	char	*uno = "+5   6";

	printf("Este es el valor de mi función: %i\n", ft_atoi(uno));
	printf("Este es el valor de la original: %i", atoi(uno));
} */
