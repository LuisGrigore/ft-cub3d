/* ************************************************************************** */
/*                                                                            */
/*   parser_color.c                                                           */
/*                                                                            */
/*   Validacion y conversion de los colores "r,g,b" de las lineas F y C.     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"

int	ft_rgb_to_int(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if (!rgb)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free_split(rgb);
	return ((r << 16) | (g << 8) | b);
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

int	ft_check_color(const char *line)
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
