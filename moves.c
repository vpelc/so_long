/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:30:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 10:54:35 by vpelc            ###   ########.fr       */
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

void	move_up(t_map *map)
{
	//mlx apllication
	write_move(map, 'U');
}

void	move_down(t_map *map)
{
	//mlx apllication
	write_move(map, 'D');
}

void	move_left(t_map *map)
{
	//mlx apllication
	write_move(map, 'L');
}

void	move_right(t_map *map)
{
	//mlx apllication
	write_move(map, 'R');
}
