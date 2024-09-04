/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:42:35 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 18:03:20 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	refresh_first(t_map *map)
{
	display(map->game, map->player_pos_y - 1, map->player_pos_x - 1, '0');
	display(map->game, map->player_pos_y - 1, map->player_pos_x, '0');
	display(map->game, map->player_pos_y - 1, map->player_pos_x + 1, '0');
	display(map->game, map->player_pos_y, map->player_pos_x - 1,'0');
	display(map->game, map->player_pos_y, map->player_pos_x, '0');
	display(map->game, map->player_pos_y, map->player_pos_x + 1, '0');
	display(map->game, map->player_pos_y + 1, map->player_pos_x - 1, '0');
	display(map->game, map->player_pos_y + 1, map->player_pos_x, '0');
	display(map->game, map->player_pos_y + 1, map->player_pos_x + 1, '0');
}

void	refresh_player(t_map *map)
{
	refresh_first(map);
	display(map->game, map->player_pos_y - 1, map->player_pos_x - 1,
		map->tab[map->player_pos_x - 1][map->player_pos_y - 1]);
	display(map->game, map->player_pos_y - 1, map->player_pos_x,
		map->tab[map->player_pos_x][map->player_pos_y - 1]);
	display(map->game, map->player_pos_y - 1, map->player_pos_x + 1,
		map->tab[map->player_pos_x + 1][map->player_pos_y - 1]);
	display(map->game, map->player_pos_y, map->player_pos_x - 1,
		map->tab[map->player_pos_x - 1][map->player_pos_y]);
	display(map->game, map->player_pos_y, map->player_pos_x,
		map->tab[map->player_pos_x][map->player_pos_y]);
	display(map->game, map->player_pos_y, map->player_pos_x + 1,
		map->tab[map->player_pos_x + 1][map->player_pos_y]);
	display(map->game, map->player_pos_y + 1, map->player_pos_x - 1,
		map->tab[map->player_pos_x - 1][map->player_pos_y + 1]);
	display(map->game, map->player_pos_y + 1, map->player_pos_x,
		map->tab[map->player_pos_x][map->player_pos_y + 1]);
	display(map->game, map->player_pos_y + 1, map->player_pos_x + 1,
		map->tab[map->player_pos_x + 1][map->player_pos_y + 1]);
}

/* void    refresh_score(t_map map)
{
    
} */
