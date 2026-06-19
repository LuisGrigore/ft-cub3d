/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_line_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 20:16:05 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 21:32:12 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../externals/libft/libft.h"
#include "../../includes/parser_internal.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_delete_list(t_line **list)
{
	t_line	*tmp;
	t_line	*lst;

	lst = *list;
	while (lst)
	{
		tmp = lst->next;
		free(lst->text);
		free(lst);
		lst = tmp;
	}
	*list = NULL;
}

void	ft_add_line(t_line *lst, t_line *new)
{
	t_line	*tmp;

	if (!lst || !new)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

t_line	*ft_new_line(char *line)
{
	t_line	*lst;

	if (!line)
		return (NULL);
	lst = (t_line *)ft_calloc(1, sizeof(t_line));
	if (!lst)
		return (NULL);
	lst->text = ft_strdup(line);
	lst->next = NULL;
	return (lst);
}

t_line	*ft_get_map_line_list(int fd)
{
	char	*line;
	char	*temp;
	t_line	*list;

	list = NULL;
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_trim_line(line);
		if (!temp)
			return (ft_delete_list(&list), NULL);
		ft_process_line(&list, temp);
		line = get_next_line(fd);
	}
	return (list);
}
