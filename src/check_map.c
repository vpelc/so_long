/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:56:27 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/10 15:09:22 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void	check_border(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->columns)
	{
		if (map->tab[0][i] != '1' || map->tab[map->lines - 1][i] != '1')
			send_error("\033[1;37m  Map not closed by walls\n\033[0m");
		i++;
	}
	while (i < map->lines)
	{
		if (map->tab[i][0] != '1' || map->tab[i][map->columns - 1] != '1')
			send_error("\033[1;37m  Map not closed by walls\n\033[0m");
		i++;
	}
}

static void	check_size(t_map *map)
{
	if ((map->columns * SQUARE_SIZE) > 1920
		|| (map->lines * SQUARE_SIZE) > 1080)
		send_error("\033[1;37m  Map to big for the screen\n\033[0m");
}

static void	check_elem_nbr(t_map *map)
{
	if (map->exit > 1)
		send_error("\033[1;37m  only one exit possible\n\033[0m");
	if (map->player > 1)
		send_error("\033[1;37m  No multiplayer\n\033[0m");
	if (map->collect == 0)
		send_error("\033[1;37m  You need gems to open the exit\n\033[0m");
	if (map->player == 0)
		send_error("\033[1;37m  You need a player\n\033[0m");
	if (map->exit == 0)
		send_error("\033[1;37m  You need an exit to leave\n\033[0m");
}

static void	check_elem(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->lines)
	{
		j = 1;
		while (j < map->columns)
		{
			if (map->tab[i][j] == 'E')
				map->exit++;
			if (map->tab[i][j] == 'P')
			{
				map->player++;
				map->player_pos_x = i;
				map->player_pos_y = j;
			}
			if (map->tab[i][j] == 'C')
				map->collect++;
			j++;
		}
		i++;
	}
	check_elem_nbr(map);
}

void	check_map(t_map *map)
{
	check_know_char(map);
	check_border(map);
	check_size(map);
	check_elem(map);
	if ((check_possible(map)) == 0)
		send_error("\033[1;37m  Impossible map\n\033[0m");
}
