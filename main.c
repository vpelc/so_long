/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:15:41 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 19:29:49 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param, void	*mlx, void *win)
{
	ft_putchar('X');
	mlx_pixel_put(mlx, win, 10, 10, 0x000000);
	return (0);
}

int	main(void)
{
	t_mlx	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "Diamond Rush");
	mlx_pixel_put(game.mlx, game.win, 250, 250, 0xFFFFFF);
	mlx_key_hook(game.win, deal_key, (void *)0);
	mlx_loop(game.mlx);
}
