/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:15:41 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 17:59:14 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	deal_key(int key, t_map *map)
{
	if (key == 53)
		close_window(map);
	if (key == 13 || key == 126)
		move_up(map);
	if (key == 1 || key == 125)
		move_down(map);
	if (key == 0 || key == 123)
		move_left(map);
	if (key == 2 || key == 124)
		move_right(map);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	t_map	map;

	check_args(argc, argv);
	map.name = argv[1];
	map.game = &game;
	fill_map(&map);
	check_map(&map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map.columns * SQUARE_SIZE,
			map.lines * SQUARE_SIZE, "Diamond Rush");
	assign_img(&game);
	display_map(&map, &game);
	mlx_key_hook(game.win, deal_key, &map);
	mlx_hook(game.win, 17, 0, close_window, &map);
	mlx_loop(game.mlx);
}
