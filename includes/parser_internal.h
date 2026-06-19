/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:24:40 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/19 21:24:41 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

# include "../../includes/parser.h"

char	*ft_get_header_line_content(const char *line, int start);
int		ft_rgb_to_int(char *color);
int		ft_check_color(const char *line);
int		ft_check_map_closed(t_parser_result *result);
int		ft_check_header(t_parser_result *result);
char	*get_next_line(int fd);
int		ft_parser_header(t_parser_result *result, int fd);
int		ft_parser_map(t_parser_result *result, int fd);
int		ft_validate_map_chars(t_parser_result *result);
void	ft_free_split(char **split);
void	ft_remove_spaces(char **str);
t_line	*ft_get_map_line_list(int fd);
void	ft_delete_list(t_line **list);
int		ft_last_valid_index(char *line);
int		ft_is_outside(char **map, int y, int x);
int		ft_find_player(char **map, int *py, int *px);
int		ft_parse_texture(char **dst, const char *line, int offset);
int		ft_parse_color(int *dst, const char *line);
int		ft_parse_texture_line(t_parser_result *result, const char *line);
int		ft_parser_header_line(t_parser_result *result, const char *line);
int		ft_process_line(t_line **list, char *temp);
char	*ft_trim_line(char *line);

void	ft_set_angle(t_parser_result *result, char angle_simbol);
int		ft_find_spawn(char **map, int *rx, int *ry);

int		ft_parser_player_spawn(t_parser_result *result);
void	ft_delete_parser_result(t_parser_result *final);
void	ft_add_line(t_line *lst, t_line *new);
t_line	*ft_new_line(char *line);

#endif
