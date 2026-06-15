/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:28 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/15 18:29:57 by lgrigore         ###   ########.fr       */
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
char			*get_next_line(int fd);
t_parse_result	*ft_parse(char *path);
void			ft_delete_parse_result(t_parse_result *result);
#endif
