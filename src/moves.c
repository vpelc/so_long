/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:30:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 18:03:32 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	write_move(t_map *map, char dir)
{
	if (map->tab[map->player_pos_x][map->player_pos_y] != 'E')
		map->tab[map->player_pos_x][map->player_pos_y] = '0';
	refresh_player(map);
	if (dir == 'U')
	{
		map->player_pos_x--;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'U');
	}
	if (dir == 'D')
	{
		map->player_pos_x++;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'D');
	}
	if (dir == 'L')
	{
		map->player_pos_y--;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'L');
	}
	if (dir == 'R')
	{
		map->player_pos_y++;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'R');
	}
	map->tab[map->player_pos_x][map->player_pos_y] = 'P';
}

void	move_up(t_map *map)
{
	if (can_up(map))
	{
		if (map->tab[map->player_pos_x - 1][map->player_pos_y] == 'C')
		{
			display(map->game, map->player_pos_y, map->player_pos_x - 1, '0');
			map->collect--;
		}
		else if (map->tab[map->player_pos_x - 1][map->player_pos_y] == 'E'
			&& map->collect == 0)
		{
			map->end = 1;
			close_window(map);
		}
		map->moves++;
		write_move(map, 'U');
	}
	else if (map->tab[map->player_pos_x - 1][map->player_pos_y] == 'E'
			&& map->collect != 0)
		not_win(map, 'U');
}

void	move_down(t_map *map)
{
	if (can_down(map))
	{
		if (map->tab[map->player_pos_x + 1][map->player_pos_y] == 'C')
		{
			display(map->game, map->player_pos_y, map->player_pos_x + 1, '0');
			map->collect--;
		}
		else if (map->tab[map->player_pos_x + 1][map->player_pos_y] == 'E'
			&& map->collect == 0)
		{
			map->end = 1;
			close_window(map);
		}
		map->moves++;
		write_move(map, 'D');
	}
	else if (map->tab[map->player_pos_x + 1][map->player_pos_y] == 'E'
			&& map->collect != 0)
		not_win(map, 'D');
}

void	move_left(t_map *map)
{
	if (can_left(map))
	{
		if (map->tab[map->player_pos_x][map->player_pos_y - 1] == 'C')
		{
			display(map->game, map->player_pos_y - 1, map->player_pos_x, '0');
			map->collect--;
		}
		else if (map->tab[map->player_pos_x][map->player_pos_y - 1] == 'E'
			&& map->collect == 0)
		{
			map->end = 1;
			close_window(map);
		}
		map->moves++;
		write_move(map, 'L');
	}
	else if (map->tab[map->player_pos_x][map->player_pos_y - 1] == 'E'
			&& map->collect != 0)
		not_win(map, 'L');
}

void	move_right(t_map *map)
{
	if (can_right(map))
	{
		if (map->tab[map->player_pos_x][map->player_pos_y + 1] == 'C')
		{
			display(map->game, map->player_pos_y + 1, map->player_pos_x, '0');
			map->collect--;
		}
		else if (map->tab[map->player_pos_x][map->player_pos_y + 1] == 'E'
			&& map->collect == 0)
		{
			map->end = 1;
			close_window(map);
		}
		map->moves++;
		write_move(map, 'R');
	}
	else if (map->tab[map->player_pos_x][map->player_pos_y + 1] == 'E'
			&& map->collect != 0)
		not_win(map, 'R');
}
