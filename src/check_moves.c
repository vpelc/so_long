/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:10:06 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/28 14:59:22 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	can_up(t_map *map)
{
	if (map->tab[map->player_pos_x + 1][map->player_pos_y] == '1')
		return (0);
	return (1);
}

int	can_down(t_map *map)
{
	if (map->tab[map->player_pos_x - 1][map->player_pos_y] == '1')
		return (0);
	return (1);
}

int	can_left(t_map *map)
{
	if (map->tab[map->player_pos_x][map->player_pos_y - 1] == '1')
		return (0);
	return (1);
}

int	can_right(t_map *map)
{
	if (map->tab[map->player_pos_x][map->player_pos_y + 1] == '1')
		return (0);
	return (1);
}
