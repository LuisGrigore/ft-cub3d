/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_list_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:24:05 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 20:24:28 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"

int	ft_process_line(t_line **list, char *temp)
{
	if (!(*list))
		*list = ft_new_line(temp);
	else
		ft_add_line(*list, ft_new_line(temp));
	free(temp);
	return (1);
}

char	*ft_trim_line(char *line)
{
	char	*temp;

	temp = ft_strtrim(line, "\n");
	free(line);
	return (temp);
}
