/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:15:41 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/19 16:56:10 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param, void	*mlx_ptr, void *win_ptr)
{
	ft_putchar('X');
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, 0x000000);
	return (0);
}

int	main(void)
{
	t_object	fo;

	fo.mlx_ptr = mlx_init();
	fo.win_ptr = mlx_new_window(fo.mlx_ptr, 500, 500, "mlx so_long");
	mlx_pixel_put(fo.mlx_ptr, fo.win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(fo.win_ptr, deal_key, (void *)0);
	mlx_loop(fo.mlx_ptr);
}
