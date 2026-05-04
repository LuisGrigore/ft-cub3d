/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:17:59 by lgrigore          #+#    #+#             */
/*   Updated: 2025/09/12 13:19:25 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"
#include <stdlib.h>

t_list	*init_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = (NULL);
	list->size = 0;
	return (list);
}

void	insert_front(t_list *list, void *data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = list->head;
	list->head = new_node;
	list->size++;
}

void	traverse_list(t_list *list, void (*func)(void *))
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		func(current->data);
		current = current->next;
	}
}

void	traverse_list_with_param(t_list *list, void (*func)(void *, void *),
		void *param)
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		func(current->data, param);
		current = current->next;
	}
}

void	*filter_with_params(t_list *list, int (*filter)(void *, void *),
		void *param)
{
	t_node	*current;

	current = list->head;
	while (current)
	{
		if (filter(current->data, param) == 1)
			return (current->data);
		current = current->next;
	}
	return (NULL);
}

void	remove_element(t_list *list, void *element,
		void (*destroy_element)(void *))
{
	t_node	*current;
	t_node	*previous;

	current = list->head;
	previous = NULL;
	while (current)
	{
		if (current->data == element)
		{
			if (previous)
				previous->next = current->next;
			else
				list->head = current->next;
			destroy_element(current->data);
			free(current);
			list->size--;
			return ;
		}
		previous = current;
		current = current->next;
	}
}

void	*get_by_index(t_list *list, int index)
{
	t_node	*current;
	int		i;

	if (list == NULL)
		return (NULL);
	if (index < 0 || index >= list->size)
		return (NULL);
	current = list->head;
	i = 0;
	while (i < index && current != NULL)
	{
		current = current->next;
		i++;
	}
	if (current != NULL)
		return (current->data);
	else
		return (NULL);
}

void	destroy_list(t_list *list, void (*destroy_data)())
{
	t_node	*current;
	t_node	*next_node;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next_node = current->next;
		destroy_data(current->data);
		free(current);
		current = next_node;
	}
	free(list);
}
