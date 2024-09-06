/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:58:17 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/06 14:18:50 by vpelc            ###   ########.fr       */
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
