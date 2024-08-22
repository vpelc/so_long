/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:45:21 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 22:28:27 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**fill_copy(t_map *map, char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			copy[i][j] = map->tab[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

void	create_copy(t_map *map, char ***map_copy)
{
	int		i;

	map_copy = malloc(sizeof(char *) * (map->lines + 1));
	if (!map_copy)
		send_error("Error malloc");
	i = 0;
	while (i < map->lines)
	{
		map_copy[i] = malloc(sizeof(char) * (map->columns + 1));
		if (!map_copy[i])
			send_error("Error malloc");
			//free every line created
		i++;
	}
	map_copy = fill_copy(map, map_copy);
}

void	ft_search(char **map, int row, int col, t_map_copy *copy)
{
	if (row < 0 || row >= copy->map->lines
		|| col < 0 || col >= copy->map->columns
		|| map[row][col] == '1' || map[row][col] == 'X')
		return ;
	if (map[row][col] == 'E')
		copy->exit = 1;
	if (map[row][col] == 'C')
		copy->collect++;
	map[row][col] = 'X';
	ft_search(map, row - 1, col, copy);
	ft_search(map, row + 1, col, copy);
	ft_search(map, row, col - 1, copy);
	ft_search(map, row, col + 1, copy);
}

int	check_possible(t_map *map)
{
	char		**map_copy;
	t_map_copy	copy;

	create_copy(map, &map_copy);
	if (!map_copy)
		send_error("Error");
	copy.map = map;
	ft_search(map_copy, map->player_pos[0], map->player_pos[1], &copy);
	//free map_copy
	return ((copy.exit == map->exit) && (copy.collect == map->collect));
}
