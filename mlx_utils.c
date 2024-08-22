/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:20:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 19:32:36 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	close_window(t_mlx *obj)
{
	mlx_clear_window(obj->mlx, obj->win);
	mlx_destroy_window(obj->mlx, obj->win);
	exit(0);
}

void	display(t_mlx *obj, int i, int j, char sqr_type)
{
	void	*img;
	int		size;

	size = SQUARE_SIZE;
	if (sqr_type == '1')
		img = mlx_xpm_file_to_image(obj->mlx, "images/wall_1.xpm",
				&size, &size);
	else if (sqr_type == '0')
		img = mlx_xpm_file_to_image(obj->mlx, "images/empty_case.xpm",
				&size, &size);
	else if (sqr_type == 'C')
		img = mlx_xpm_file_to_image(obj->mlx, "images/collectible.xpm",
				&size, &size);
	else if (sqr_type == 'E')
		img = mlx_xpm_file_to_image(obj->mlx, "images/exit.xpm",
				&size, &size);
	else if (sqr_type == 'P')
		img = mlx_xpm_file_to_image(obj->mlx, "images/player_left.xpm",
				&size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, img, (i * size), (j * size));
}
