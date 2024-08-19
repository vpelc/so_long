/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:30:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/19 17:11:01 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	write_move(t_map *map, char dir)
{
	map->tab[map->player_pos[0]][map->player_pos[1]] == '0';
	if (dir == 'U')
		map->player_pos[0]++;
	if (dir == 'D')
		map->player_pos[0]--;
	if (dir == 'L')
		map->player_pos[1]--;
	if (dir == 'R')
		map->player_pos[1]++;
	map->tab[map->player_pos[0]][map->player_pos[1]] == 'P';
}
