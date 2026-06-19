/* ************************************************************************** */
/*                                                                            */
/*   parser_check.c                                                           */
/*                                                                            */
/*   Comprobaciones finales sobre la cabecera ya parserada: que no falte      */
/*   ningun campo y que las texturas referenciadas existan en disco.         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/parser_internal.h"
# include "../../externals/libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int	ft_check_file(const char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	ft_check_header(t_parser_result *result)
{
	if (!result->text_no_path || !result->text_so_path
		|| !result->text_we_path || !result->text_ea_path)
		return (printf("Error: faltan texturas\n"), -1);
	if (result->colorF == -1 || result->colorC == -1)
		return (printf("Error: faltan colores\n"), -1);
	if (!ft_check_file(result->text_no_path)
		|| !ft_check_file(result->text_so_path)
		|| !ft_check_file(result->text_we_path)
		|| !ft_check_file(result->text_ea_path))
		return (printf("Error: textura inválida\n"), -1);
	return (1);
}
