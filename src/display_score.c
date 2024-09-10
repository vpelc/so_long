/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:58:17 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/10 14:57:14 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	*display_numbers(t_map *map, int nbr)
{
	if (nbr == 0)
		return (map->game->nbr_0);
	else if (nbr == 1)
		return (map->game->nbr_1);
	else if (nbr == 2)
		return (map->game->nbr_2);
	else if (nbr == 3)
		return (map->game->nbr_3);
	else if (nbr == 4)
		return (map->game->nbr_4);
	else if (nbr == 5)
		return (map->game->nbr_5);
	else if (nbr == 6)
		return (map->game->nbr_6);
	else if (nbr == 7)
		return (map->game->nbr_7);
	else if (nbr == 8)
		return (map->game->nbr_8);
	else if (nbr == 9)
		return (map->game->nbr_9);
	else
		return (NULL);
}

void	not_win(t_map *map, char dir)
{
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
	refresh_score(map);
}
