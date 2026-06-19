/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:28 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/18 17:51:23 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H



typedef struct s_line
{
	char			*text;
	struct s_line	*next;
}					t_line;

typedef struct s_parser_result
{
	char			**map;
	float			starting_x;
	float			starting_y;
	float			s_angle;
	int				colorF;
	int				colorC;
	char			*text_no_path;
	char			*text_so_path;
	char			*text_we_path;
	char			*text_ea_path;
}					t_parser_result;

//**************PARSER*****************************
t_parser_result	*ft_parser(char *path);
void			ft_delete_parser_result(t_parser_result *result);
#endif
