/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:15:51 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 20:15:53 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"

int	ft_skip_spc(const char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i += 1;
	return (i);
}

void	ft_remove_spaces(char **str)
{
	int		i;
	char	*temp;

	i = ft_skip_spc(*str);
	temp = *str;
	*str = ft_strdup(temp + i);
	free(temp);
}

int	ft_len_dir(const char *line, int start)
{
	int	len;

	len = start;
	while (line[len] && line[len] != ' ' && line[len] != '\t'
		&& line[len] != '\n')
		len++;
	return (len);
}

char	*ft_get_header_line_content(const char *line, int start)
{
	int	end;

	start += ft_skip_spc(line + start);
	end = ft_len_dir(line, start);
	if (end <= start)
		return (NULL);
	return (ft_substr(line, start, end - start));
}
