/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:18:08 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/12 13:19:36 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct t_node
{
	void			*data;
	struct t_node	*next;
}					t_node;

typedef struct s_list
{
	t_node			*head;
	int				size;
}					t_list;

t_list				*init_list(void);
void				insert_front(t_list *list, void *data);
void				traverse_list(t_list *list, void (*func)(void *));
void				traverse_list_with_param(t_list *list, void (*func)(void *,
							void *), void *param);
void				*filter_with_params(t_list *list, int (*filter)(void *,
							void *), void *param);
void				remove_element(t_list *list, void *element,
						void (*destroy_element)());
void				*get_by_index(t_list *list, int index);
void				destroy_list(t_list *list, void (*destroy_data)());

#endif
