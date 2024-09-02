/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:30:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/02 20:59:27 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	write_move(t_map *map, char dir)
{
	map->tab[map->player_pos_x][map->player_pos_y] = '0';
	// display(map->game, map->player_pos_y, map->player_pos_x, '0');
	if (dir == 'U')
	{
		map->player_pos_x--;
		// display_player(map->game, map->player_pos_y, map->player_pos_x, 'U');
	}
	if (dir == 'D')
	{
		map->player_pos_x++;
		// display_player(map->game, map->player_pos_y, map->player_pos_x, 'D');
	}
	if (dir == 'L')
	{
		map->player_pos_y--;
		// display_player(map->game, map->player_pos_y, map->player_pos_x, 'L');
	}
	if (dir == 'R')
	{
		map->player_pos_y++;
		// display_player(map->game, map->player_pos_y, map->player_pos_x, 'R');
	}
	map->tab[map->player_pos_x][map->player_pos_y] = 'P';
}

void	move_up(t_map *map)
{
	if (can_up(map))
	{
		if (map->tab[map->player_pos_x - 1][map->player_pos_y] == 'C')
			map->collect--;
		else if (map->tab[map->player_pos_x - 1][map->player_pos_y] == 'E'
			&& map->collect == 0)
			map->end = 1;
		map->moves++;
		write_move(map, 'U');
	}
}

void	move_down(t_map *map)
{
	if (can_down(map))
	{
		if (map->tab[map->player_pos_x + 1][map->player_pos_y] == 'C')
			map->collect--;
		else if (map->tab[map->player_pos_x + 1][map->player_pos_y] == 'E'
			&& map->collect == 0)
			map->end = 1;
		map->moves++;
		write_move(map, 'D');
	}
}

void	move_left(t_map *map)
{
	if (can_left(map))
	{
		if (map->tab[map->player_pos_x][map->player_pos_y - 1] == 'C')
			map->collect--;
		else if (map->tab[map->player_pos_x][map->player_pos_y - 1] == 'E'
			&& map->collect == 0)
			map->end = 1;
		map->moves++;
		write_move(map, 'L');
	}
}

void	move_right(t_map *map)
{
	if (can_right(map))
	{
		if (map->tab[map->player_pos_x][map->player_pos_y + 1] == 'C')
			map->collect--;
		else if (map->tab[map->player_pos_x][map->player_pos_y + 1] == 'E'
			&& map->collect == 0)
			map->end = 1;
		map->moves++;
		write_move(map, 'R');
	}
}
