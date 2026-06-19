/* ************************************************************************** */
/*                                                                            */
/*   parser_map.c                                                             */
/*                                                                            */
/*   Conversion de la t_line lista en el mapa char** normalizado            */
/*   (todas las filas rellenadas hasta el mismo ancho).                      */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"

static char	*ft_reg_line(char *line, int w)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(w + 1);
	if (!str)
		return (NULL);
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (i < w)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_get_width(t_line *lst)
{
	t_line	*tmp;
	int		max_width;
	int		len;

	tmp = lst;
	max_width = 0;
	while (tmp)
	{
		len = ft_strlen(tmp->text);
		if (max_width < len)
			max_width = len;
		tmp = tmp->next;
	}
	return (max_width);
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

char	**ft_norm_map(t_line *lst)
{
	char	**map;
	t_line	*tmp;
	int		i;

	if (!lst)
		return (NULL);
	map = ft_calloc(ft_len_lines(lst) + 1, sizeof(char *));
	if (!map)
		return (NULL);
	tmp = lst;
	i = 0;
	while (tmp)
	{
		map[i] = ft_reg_line(tmp->text, ft_get_width(lst));
		if (!map[i])
			return (ft_free_split(map), NULL);
		tmp = tmp->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	ft_parser_map(t_parser_result *result, int fd)
{
	t_line	*line;

	line = ft_get_map_line_list(fd);
	if (!line)
		return (-1);
	result->map = ft_norm_map(line);
	ft_delete_list(&line);
	return (1);
}
