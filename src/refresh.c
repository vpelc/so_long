/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:42:35 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/06 15:00:02 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	refresh_first(t_map *map)
{
	display(map->game, map->player_pos_y - 1, map->player_pos_x, '0');
	display(map->game, map->player_pos_y, map->player_pos_x - 1,'0');
	display(map->game, map->player_pos_y, map->player_pos_x, '0');
	display(map->game, map->player_pos_y, map->player_pos_x + 1, '0');
	display(map->game, map->player_pos_y + 1, map->player_pos_x, '0');
}

void	refresh_player(t_map *map)
{
	refresh_first(map);
	display(map->game, map->player_pos_y - 1, map->player_pos_x,
		map->tab[map->player_pos_x][map->player_pos_y - 1]);
	display(map->game, map->player_pos_y, map->player_pos_x - 1,
		map->tab[map->player_pos_x - 1][map->player_pos_y]);
	display(map->game, map->player_pos_y, map->player_pos_x,
		map->tab[map->player_pos_x][map->player_pos_y]);
	display(map->game, map->player_pos_y, map->player_pos_x + 1,
		map->tab[map->player_pos_x + 1][map->player_pos_y]);
	display(map->game, map->player_pos_y + 1, map->player_pos_x,
		map->tab[map->player_pos_x][map->player_pos_y + 1]);
}

static void	refresh_score_big(t_map *map)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->win,
			map->game->nbr_9, SQUARE_SIZE + (32 * i), 8);
		i++;
	}
}

void	refresh_score(t_map *map)
{
	int	i;
	int	m;

	i = 0;
	m = map->moves;
	display(map->game, 0, 0, '1');
	display(map->game, 1, 0, '1');
	display(map->game, 2, 0, '1');
	if (m > 999)
	{
		refresh_score_big(map);
		return ;
	}

	mlx_put_image_to_window(map->game->mlx, map->game->win,
		display_numbers(map, (m / 100)), SQUARE_SIZE + (32 * i), 8);
	m %= 100;
	i++;
	mlx_put_image_to_window(map->game->mlx, map->game->win,
		display_numbers(map, (m / 10)), SQUARE_SIZE + (32 * i), 8);
	m %= 10;
	i++;
	mlx_put_image_to_window(map->game->mlx, map->game->win,
		display_numbers(map, (m)), SQUARE_SIZE + (32 * i), 8);
}
