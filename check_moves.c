/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:10:06 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/19 17:20:58 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	can_up(t_map *map)
{
	if (map->tab[map->player_pos[0] + 1][map->player_pos[1]] == '1')
		return (0);
	return (1);
}

int	can_down(t_map *map)
{
	if (map->tab[map->player_pos[0] - 1][map->player_pos[1]] == '1')
		return (0);
	return (1);
}

int	can_left(t_map *map)
{
	if (map->tab[map->player_pos[0]][map->player_pos[1] - 1] == '1')
		return (0);
	return (1);
}

int	can_right(t_map *map)
{
	if (map->tab[map->player_pos[0]][map->player_pos[1] + 1] == '1')
		return (0);
	return (1);
}
