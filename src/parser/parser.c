/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:16:19 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 22:33:24 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_parser_result	*ft_parser_init(char *p, int *fd)
{
	t_parser_result	*result;
	char			**s;
	int				last;

	last = 0;
	s = ft_split(p, '/');
	while (s[last])
		last++;
	if (ft_strlen(s[last - 1]) <= 4 || ft_strcmp(p + ft_strlen(p) - 4, ".cub"))
		return (printf("Error, wrong file format\n"), NULL);
	ft_free_split(s);
	*fd = open(p, O_RDONLY);
	if (*fd < 0)
		return (printf("Error, file not found\n"), NULL);
	result = malloc(sizeof(t_parser_result));
	if (!result)
		return (close(*fd), NULL);
	result->map = NULL;
	return (result);
}

static t_parser_result	*ft_parser_fail(t_parser_result *r, int fd, char *msg)
{
	printf("%s\n", msg);
	if (fd >= 0)
		close(fd);
	ft_delete_parser_result(r);
	return (NULL);
}

static int	ft_parser_read(t_parser_result *result, int fd)
{
	if (ft_parser_header(result, fd) == -1)
		return (-1);
	if (ft_check_header(result) == -1)
		return (-1);
	if (ft_parser_map(result, fd) == -1)
		return (-1);
	return (1);
}

t_parser_result	*ft_parser(char *path)
{
	t_parser_result	*result;
	int				fd;

	fd = -1;
	result = ft_parser_init(path, &fd);
	if (!result)
		return (NULL);
	if (ft_parser_read(result, fd) == -1)
		return (ft_parser_fail(result, fd, "Error parsing file"));
	close(fd);
	fd = -1;
	if (ft_validate_map_chars(result) == -1)
		return (ft_parser_fail(result, -1, "Error: invalid char in map"));
	if (ft_check_map_closed(result) == -1)
		return (ft_parser_fail(result, -1, "Error: map not closed"));
	if (ft_parser_player_spawn(result) == -1)
		return (ft_parser_fail(result, -1, "Error parsing player"));
	return (result);
}
