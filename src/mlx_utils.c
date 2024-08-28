/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:20:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/28 16:01:06 by vpelc            ###   ########.fr       */
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

	size = SQUARE_SIZE;
	if (sqr_type == '1')
		img = mlx_xpm_file_to_image(obj->mlx, "images/wall_1.xpm",
				&size, &size);
	else if (sqr_type == '0')
		img = mlx_xpm_file_to_image(obj->mlx, "images/vines.xpm",
				&size, &size);
	else if (sqr_type == 'C')
		img = mlx_xpm_file_to_image(obj->mlx, "images/collectible.xpm",
				&size, &size);
	else if (sqr_type == 'E')
		img = mlx_xpm_file_to_image(obj->mlx, "images/exit.xpm",
				&size, &size);
	else if (sqr_type == 'L')
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
	mlx_put_image_to_window(obj->mlx, obj->win, img, (i * size), (j * size));
}

void	display_map(t_map *map, t_game *obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			display(obj, j, i, map->tab[i][j]);
			j++;
		}
		i++;
	}
}
