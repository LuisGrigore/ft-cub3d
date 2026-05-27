/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 17:15:48 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/24 17:16:22 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static int	ft_check_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	ft_isnumeric(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int ft_check_header_f_c(const char *line)
{
	int		i;
	int		num;
	int		count;
	char	**split;

	count = 0;
	split = ft_split(line, ',');
	if (!split)
		return (0);
	while (split[count])
		count++;
	if (count != 3)
		return (ft_free_split(split), 0);
	i = 0;
	while (i < 3)
	{
		if (!ft_isnumeric(split[i]))
			return (ft_free_split(split), 0);
		num = ft_atoi(split[i]);
		if (num < 0 || num > 255)
			return (ft_free_split(split), 0);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_check_header(t_header *h)
{
	if (!h->text_no || !h->text_so || !h->text_we || !h->text_ea)
		return (printf("Error: faltan texturas\n"), 0);
	if (!h->color_f || !h->color_c)
		return (printf("Error: faltan colores\n"), 0);
	if (!ft_check_file(h->text_no)
		|| !ft_check_file(h->text_so)
		|| !ft_check_file(h->text_we)
		|| !ft_check_file(h->text_ea))
		return (printf("Error: textura inválida\n"), 0);
	if (!ft_check_header_f_c(h->color_f)
		|| !ft_check_header_f_c(h->color_c))
		return (printf("Error: color inválido\n"), 0);
	return (1);
}
