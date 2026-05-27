/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:34 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/22 20:00:35 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parseo.h"

static char	*ft_create(char **stack, char **buffer)
{
	char	*tmp;

	if (!*stack)
		tmp = ft_strdup(*buffer);
	else
		tmp = ft_strjoin(*stack, *buffer);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static int	ft_readfd(int fd, char **stack)
{
	char	*buffer;
	char	*tmp;
	ssize_t	rd;

	buffer = (char *)malloc((1024 + 1) * sizeof(char));
	if (!buffer)
		return (-1);
	rd = 1;
	while (rd > 0 && (!*stack || !ft_strchr(*stack, '\n')))
	{
		rd = read(fd, buffer, 1024);
		if (rd < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[rd] = '\0';
		tmp = ft_create(stack, &buffer);
		free(*stack);
		*stack = tmp;
	}
	free(buffer);
	if (rd == 0 && (!*stack || *stack[0] == '\0'))
		return (0);
	return (1);
}

static void	ft_replace(char **stack, char **line, char **rest)
{
	size_t	i;
	size_t	len;

	i = 0;
	while ((*stack)[i] && (*stack)[i] != '\n')
		i++;
	if ((*stack)[i] == '\n')
	{
		*line = ft_substr(*stack, 0, i + 1);
		len = ft_strlen(*stack) - (i + 1);
		*rest = ft_substr(*stack, i + 1, len);
	}
	else
	{
		*line = ft_substr(*stack, 0, i);
		*rest = NULL;
	}
	if (!*line)
	{
		free(*line);
		line = NULL;
	}
}

static char	*ft_getline(char **stack)
{
	char	*line;
	char	*rest;

	if (!*stack || !**stack || !stack)
	{
		if (!*stack || !stack)
		{
			free(*stack);
			*stack = NULL;
		}
		return (NULL);
	}
	else
		ft_replace(stack, &line, &rest);
	free(*stack);
	if (rest && !*rest)
	{
		free(rest);
		rest = NULL;
	}
	*stack = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	int			status;

	if (fd < 0)
		return (NULL);
	status = ft_readfd(fd, &stack);
	if (status == -1)
	{
		if (stack)
		{
			free(stack);
			stack = NULL;
		}
		return (NULL);
	}
	if (!stack || !*stack)
	{
		if (stack)
		{
			free(stack);
			stack = NULL;
		}
		return (NULL);
	}
	return (ft_getline(&stack));
}
