/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:20:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/02 21:13:23 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	close_window(t_game *obj)
{
	mlx_clear_window(obj->mlx, obj->win);
	mlx_destroy_window(obj->mlx, obj->win);
	exit(0);
}

void	display(t_game *obj, int i, int j, char sqr_type)
{
	void	*img;
	int		size;

	size = 30;
	if (sqr_type == '1')
		img = mlx_xpm_file_to_image(obj->mlx, "images/wall_1.xpm",
				&size, &size);
	else if (sqr_type == '0')
		img = mlx_xpm_file_to_image(obj->mlx, "images/vines.xpm",
				&size, &size);
	else if (sqr_type == 'C')
		img = mlx_xpm_file_to_image(obj->mlx, "images/gem.xpm",
				&size, &size);
	else if (sqr_type == 'E')
		img = mlx_xpm_file_to_image(obj->mlx, "images/exit.xpm",
				&size, &size);
	else
		return ;
	mlx_put_image_to_window(obj->mlx, obj->win, img,
		(i * size), (j * size));
}
void	display_player(t_game *obj, int i, int j, char sqr_type)
{
	void	*img;
	int		size;

	size = PLAYER_SIZE;
	if (sqr_type == 'L' || sqr_type == 'P')
		img = mlx_xpm_file_to_image(obj->mlx, "images/player_left.xpm",
				&size, &size);
	else if (sqr_type == 'R')
		img = mlx_xpm_file_to_image(obj->mlx, "images/player_right.xpm",
				&size, &size);
	else if (sqr_type == 'U')
		img = mlx_xpm_file_to_image(obj->mlx, "images/player_up.xpm",
				&size, &size);
	else if (sqr_type == 'D')
		img = mlx_xpm_file_to_image(obj->mlx, "images/player_down.xpm",
				&size, &size);
	else
		return ;
	mlx_put_image_to_window(obj->mlx, obj->win, img,
		(i * (size - 9)), (j * (size - 9)));
}

void	display_first(t_map *map, t_game *obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			display(obj, j, i, '0');
			j++;
		}
		i++;
	}
}

void	display_map(t_map *map, t_game *obj)
{
	int	i;
	int	j;

	display_first(map, obj);
	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->tab[i][j] == 'P')
				display_player(obj, j, i, map->tab[i][j]);
			else
				display(obj, j, i, map->tab[i][j]);

			j++;
		}
		i++;
	}
}
