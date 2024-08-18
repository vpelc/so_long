/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:30:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/13 13:44:57 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	write_move(t_map *map, char dir)
{
	map->tab[map->player_pos[0]][map->player_pos[1]] == '0';
	if (dir == 'N')
		map->player_pos[0]++;
	if (dir == 'S')
		map->player_pos[0]--;
	if (dir == 'W')
		map->player_pos[1]--;
	if (dir == 'E')
		map->player_pos[1]++;
	map->tab[map->player_pos[0]][map->player_pos[1]] == 'P';
}

