/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:47:20 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 19:29:33 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	send_error(char *error)
{
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
	// system("leaks so_long");
	exit(0);
}

void	not_win(t_map *map, char dir)
{
	map->tab[map->player_pos_x][map->player_pos_y] = '0';
	refresh_player(map);
	if (dir == 'U')
	{
		map->player_pos_x--;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'U');
	}
	if (dir == 'D')
	{
		map->player_pos_x++;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'D');
	}
	if (dir == 'L')
	{
		map->player_pos_y--;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'L');
	}
	if (dir == 'R')
	{
		map->player_pos_y++;
		display_player(map->game, map->player_pos_y, map->player_pos_x, 'R');
	}
}
