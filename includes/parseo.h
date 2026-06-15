/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:28 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/15 04:09:25 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSEO_H
# define PARSEO_H

# include "../libft/libft.h"
# include "./player.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_line
{
	char			*text;
	struct s_line	*next;
}					t_line;

// typedef struct s_header
// {
// 	char			*text_no;
// 	char			*text_so;
// 	char			*text_we;
// 	char			*text_ea;
// 	char			*color_f;
// 	char			*color_c;

// }					t_header;

// typedef struct s_map
// {
// 	char			**grid;
// 	int				height;
// 	int				len_max;

// }					t_map;

// typedef struct s_parse
// {
// 	t_header		*header;
// 	t_map			*map;
// 	float			player_x;
// 	float			player_y;
// 	int				i;
// 	int				fd;
// 	char			player_dir;
// }					t_parse;

typedef struct s_parse_result
{
	char			**map;
	float			starting_x;
	float			starting_y;
	float			starting_angle;
	int				colorF;
	int				colorC;
	char			*text_no_path;
	char			*text_so_path;
	char			*text_we_path;
	char			*text_ea_path;
}					t_parse_result;

//**************PARSE*****************************
// int				ft_init_parse(t_parse *parse);
char			*get_next_line(int fd);
t_parse_result	*ft_parse(char *path);
// char			*ft_parse_header(t_parse *parse);
// int				ft_parse_header_line(t_header *head, const char *line);
// int				ft_check_header(t_header *h);
// int				ft_read_map(t_parse *parse, t_line **list);
// char			**ft_norm_map(t_line *lst, t_parse *parse);
// int				ft_val_map(char **map, int height, t_parse *parse);
// t_parse_result	*ft_final_parse(t_parse *parse);

//**************UTILS*****************************
// void			ft_skip_spc(const char *line, int *i);
// int				ft_len_dir(const char *line, int start);
// t_line			*ft_new_line(char *line);
// void			ft_add_line(t_line **lst, t_line *new);
// int				ft_len_lines(t_line *list);
// int				ft_is_valid(char c);
// int				ft_check_each_space(char **map, int y, int x);
// int				ft_is_space(char c);
// int				ft_check_inside(char **map, int y, int x);
// void			ft_assign(float **px, float **py, int pos[2], char **map);

//**************CLEAN*****************************
// void			ft_free_split(char **split);
// void			ft_delete_list(t_line **list);
// void			ft_free_parse(t_parse **parse);
void			ft_delete_parse_result(t_parse_result *result);
#endif
