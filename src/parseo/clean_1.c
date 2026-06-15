/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:23 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/15 02:33:37 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

static void	ft_clean_header(t_header *h)
{
	if (!h)
		return ;
	free(h->text_no);
	free(h->text_so);
	free(h->text_we);
	free(h->text_ea);
	free(h->color_f);
	free(h->color_c);
}

static void	ft_clean_map(t_map **map)
{
	int	i;

	if (!map || !*map || !(*map)->grid)
		return ;
	i = 0;
	while ((*map)->grid[i])
		free((*map)->grid[i++]);
	free((*map)->grid);
}

void	ft_free_parse(t_parse **parse)
{
	if (!parse || !*parse)
		return ;
	ft_clean_header((*parse)->header);
	ft_clean_map(&(*parse)->map);
	free((*parse)->header);
	free((*parse)->map);
	free(*parse);
	*parse = NULL;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_delete_list(t_line **list)
{
	t_line	*tmp;
	t_line	*lst;

	lst = *list;
	while (lst)
	{
		tmp = lst->next;
		free(lst->text);
		free(lst);
		lst = tmp;
	}
	*list = NULL;
}
