/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:20:30 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 18:03:56 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	display(t_game *obj, int i, int j, char sqr_type)
{
	void	*img;

	if (sqr_type == '1')
		img = obj->img_1;
	else if (sqr_type == '0')
		img = obj->img_0;
	else if (sqr_type == 'C')
		img = obj->img_c;
	else if (sqr_type == 'E')
		img = obj->img_e;
	else
		return ;
	mlx_put_image_to_window(obj->mlx, obj->win, img,
		(i * SQUARE_SIZE), (j * SQUARE_SIZE));
}


void	display_player(t_game *obj, int i, int j, char sqr_type)
{
	void	*img;

	if (sqr_type == 'L' || sqr_type == 'P')
		img = obj->img_pl;
	else if (sqr_type == 'R')
		img = obj->img_pr;
	else if (sqr_type == 'U')
		img = obj->img_pu;
	else if (sqr_type == 'D')
		img = obj->img_pd;
	else
		return ;
	mlx_put_image_to_window(obj->mlx, obj->win, img,
		(i * SQUARE_SIZE) - 4, (j * SQUARE_SIZE) - 2);
}

static void	display_first(t_map *map, t_game *obj)
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
