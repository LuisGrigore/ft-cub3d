/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 23:30:03 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/11 23:33:08 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_length(int n)
{
	int	len;

	if (n <= 0)
	{
		len = 1;
	}
	else
	{
		len = 0;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int len;
	char *str;
	long num;

	len = get_length(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len-- > 0)
	{
		if (str[len] == '-')
			break ;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}