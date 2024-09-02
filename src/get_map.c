/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:40:23 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/01 16:04:33 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int	ft_strlen_next(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static void	read_map(t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map->name, O_RDONLY);
	if (fd == -1)
		send_error("Error with the file");
	line = get_next_line(fd);
	map->columns = ft_strlen_next(line);
	map->lines = 0;
	while (line)
	{
		if (map->columns != ft_strlen_next(line))
			send_error("Error not a square");
		map->lines++;
		line = get_next_line(fd);
	}
	free(line);
}

void	fill_map(t_map *map)
{
	int		i;
	int		fd;
	int		ll;
	char	*line;

	read_map(map);
	fd = open(map->name, O_RDONLY);
	map->tab = malloc(sizeof(char *) * map->lines);
	line = get_next_line(fd);
	ll = ft_strlen_next(line);
	i = 0;
	while (line)
	{
		map->tab[i] = malloc(sizeof(char) * ll);
		map->tab[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->end = 0;
	map->moves = 0;
	map->player = 0;
	map->collect = 0;
	free(line);
}
