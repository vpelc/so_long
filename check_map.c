/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:27 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 22:25:58 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check_border(t_map map)
{
	int	i;

	i = 0;
	while (i < map.columns)
	{
		if (map.tab[0][i] != '1' || map.tab[map.lines - 1][i] != '1')
			pass;
			//error call
		i++;
	}
	while (i < map.lines)
	{
		if (map.tab[i][0] != '1' || map.tab[i][map.columns - 1] != '1')
			pass;
			//error call 
		i++;
	}
}

void	check_elem(t_map map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map.lines)
	{
		j = 1;
		while (j < map.columns)
		{
			if (map.tab[i][j] == 'E')
				map.exit++;
			if (map.exit > 1)
				send_error("Error only one exit possible");
			if (map.tab[i][j] == 'P')
			{
				map.player++;
				map.player_pos[0] = i;
				map.player_pos[1] = j;
			}
			if (map.player > 1)
				send_error("Error no multiplayer");
			if (map.tab[i][j] == 'C')
				map.collect++;
			j++;
		}
		i++;
	}
	if (map.collect == 0)
		send_error("Error you nees gems to open the exit");
}
