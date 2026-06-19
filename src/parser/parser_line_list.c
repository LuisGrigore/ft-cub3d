/* ************************************************************************** */
/*                                                                            */
/*   parser_line_list.c                                                       */
/*                                                                            */
/*   Construccion y liberacion de la lista enlazada de lineas crudas         */
/*   del mapa, leidas directamente del archivo con get_next_line.            */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"

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

	line = get_next_line(fd);
	list = NULL;
	while (line)
	{
		temp = ft_strtrim(line, "\n");
		free(line);
		if (!temp)
		{
			ft_delete_list(&list);
			return (NULL);
		}
		if (temp[0] == '\0')
		{
			free(temp);
			line = get_next_line(fd);
			continue ;
		}
		if (!list)
			list = ft_new_line(temp);
		else
			ft_add_line(list, ft_new_line(temp));
		free(temp);
		line = get_next_line(fd);
	}
	return (list);
}
