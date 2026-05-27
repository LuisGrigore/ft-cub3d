/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:26:42 by juan-her          #+#    #+#             */
/*   Updated: 2026/05/24 21:25:55 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parseo.h"

void	ft_skip_spc(const char *line, int *i)
{
	while(line[*i] && (line[*i] == ' ' || line[*i] == '\t'))
		*i += 1;
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

t_line *ft_new_line(char *line)
{
	t_line *lst;
	
	if (!line)
		return (NULL);
	lst = (t_line *) ft_calloc(1, sizeof(t_line));
	if (!lst)
		return (NULL);
	lst->text = ft_strdup(line);
	lst->next = NULL;
	return (lst);
}

void	ft_add_line(t_line **lst, t_line *new)
{
	t_line	*tmp;
	
	if (!*lst || !new)
		return ;	
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	ft_len_lines(t_line *list)
{
	t_line	*tmp;
	int		i;

	if (!list)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

