/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:47:20 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/10 15:10:53 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	send_error(char *error)
{
	write(2, "\033[1;31mError!\033[0m", 17);
	write(2, error, ft_strlen(error));
	exit(1);
}

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->lines)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
}

static void	free_img(t_game *obj)
{
	mlx_destroy_image(obj->mlx, obj->img_1);
	mlx_destroy_image(obj->mlx, obj->img_0);
	mlx_destroy_image(obj->mlx, obj->img_c);
	mlx_destroy_image(obj->mlx, obj->img_e);
	mlx_destroy_image(obj->mlx, obj->img_pl);
	mlx_destroy_image(obj->mlx, obj->img_pr);
	mlx_destroy_image(obj->mlx, obj->img_pu);
	mlx_destroy_image(obj->mlx, obj->img_pd);
}

int	close_window(t_map *map)
{
	mlx_clear_window(map->game->mlx, map->game->win);
	mlx_destroy_window(map->game->mlx, map->game->win);
	free_img(map->game);
	free_map(map);
	exit(0);
}

void	check_know_char(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->tab[i][j] != 'P' && map->tab[i][j] != 'E'
				&& map->tab[i][j] != 'C'
				&& map->tab[i][j] != '1' && map->tab[i][j] != '0')
				send_error("\033[1;37m Not autorized character used\033[0m");
			j++;
		}
		i++;
	}
}
