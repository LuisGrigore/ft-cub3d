/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multifree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:21:26 by juan-her          #+#    #+#             */
/*   Updated: 2026/02/18 16:41:36 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_multifree(int n, ...)
{
	void	**ptr;
	int		i;
	va_list	ap;

	if (n < 1)
		return ;
	i = 0;
	va_start(ap, n);
	while (i < n)
	{
		ptr = va_arg(ap, void **);
		if (*ptr)
			free(*ptr);
		*ptr = NULL;
		i++;
	}
	va_end(ap);
}
