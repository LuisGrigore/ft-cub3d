/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 21:56:11 by lgrigore          #+#    #+#             */
/*   Updated: 2026/06/14 22:58:30 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parseo.h"

void	ft_delete_parse_result(t_parse_result **final)
{
	int	i;

	if (!final || !*final)
		return ;
	if ((*final)->map)
	{
		if ((*final)->map->grid)
		{
			i = 0;
			while ((*final)->map->grid[i])
				free((*final)->map->grid[i++]);
			free((*final)->map->grid);
		}
		free((*final)->map);
	}
	free((*final)->text_no_path);
	free((*final)->text_so_path);
	free((*final)->text_we_path);
	free((*final)->text_ea_path);
	free((*final)->color_f);
	free((*final)->color_c);
	free(*final);
	*final = NULL;
}