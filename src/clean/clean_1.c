/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-her <juan-her@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:00:23 by juan-her          #+#    #+#             */
/*   Updated: 2026/06/13 16:31:12 by juan-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

void	ft_clean_header(t_header *h)
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

void	ft_clean_map(t_map **map)
{
	int	i;

	if (!map || !*map || !(*map)->map)
		return ;
	i = 0;
	while ((*map)->map[i])
		free((*map)->map[i++]);
	free((*map)->map);
}

void	ft_free_parseo(t_parseo **parse)
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

void	ft_del_list(t_line **list)
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
