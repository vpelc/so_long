/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:40:23 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/13 13:49:28 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_strlen_next(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

t_map	read_map(t_map map)
{
	int		fd;
	char	*line;

	fd = open(map.name, O_RDONLY);
	if (fd == -1)
		pass ;
		//error call
	line = get_next_line(fd);
	map.columns = ft_strlen_next(line);
	while (line)
	{
		if (map.columns != ft_strlen_next(line))
			pass ;
			//error call
		map.lines++;
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

t_map	fill_map(t_map map)
{
	int		i;
	int		fd;
	int		ll;
	char	*line;

	fd = open(map.name, O_RDONLY);
	map.tab = malloc(sizeof(char *) * map.lines);
	line = get_next_line(fd);
	ll = ft_strlen_next(line);
	while (line)
	{
		map.tab[i] = malloc(sizeof(char) * ll);
		map.tab[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map.end = 0;
	free(line);
	return (map);
}
