#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "../../includes/parser.h"


char	*ft_get_header_line_content(const char *line, int start);
int		ft_rgb_to_int(char *color);
int		ft_check_color(const char *line);
int		ft_check_map_closed(t_parser_result *result);
int		ft_check_header(t_parser_result *result);
char	*get_next_line(int fd);
int	ft_parser_header(t_parser_result *result, int fd);
int	ft_parser_map(t_parser_result *result, int fd);
int	ft_validate_map_chars(t_parser_result *result);
void	ft_free_split(char **split);
void	ft_remove_spaces(char **str);
t_line	*ft_get_map_line_list(int fd);
void	ft_delete_list(t_line **list);


#endif
