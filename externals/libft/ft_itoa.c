/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:38:41 by juan-her          #+#    #+#             */
/*   Updated: 2025/10/06 16:33:51 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_neg(int n)
{
	if (n < 0)
		return (-(long)n);
	return (n);
}

static char	*ft_create(char *str, long nb, int len, int sign)
{
	str[len + sign] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
	}
	else
	{
		while (nb > 0)
		{
			str[--len + sign] = (nb % 10) + '0';
			nb /= 10;
		}
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	long	len;
	int		sign;
	long	temp_nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0);
	nb = ft_neg(n);
	len = 0;
	if (nb == 0)
		len = 1;
	temp_nb = nb;
	while (temp_nb > 0)
	{
		temp_nb /= 10;
		len++;
	}
	str = (char *)malloc(len + sign + 1);
	if (!str)
		return (NULL);
	return (ft_create(str, nb, len, sign));
}
