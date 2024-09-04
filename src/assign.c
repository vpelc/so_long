/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:33:56 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 18:11:42 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	assign_img(t_game *obj)
{
	int		size_i;
	int		size_p;

	size_i = SQUARE_SIZE;
	size_p = PLAYER_SIZE;
	obj->img_1 = mlx_xpm_file_to_image(obj->mlx, "images/wall_1.xpm",
			&size_i, &size_i);
	obj->img_0 = mlx_xpm_file_to_image(obj->mlx, "images/vines.xpm",
			&size_i, &size_i);
	obj->img_c = mlx_xpm_file_to_image(obj->mlx, "images/gem.xpm",
			&size_i, &size_i);
	obj->img_e = mlx_xpm_file_to_image(obj->mlx, "images/exit.xpm",
			&size_i, &size_i);
	obj->img_pl = mlx_xpm_file_to_image(obj->mlx, "images/player_left.xpm",
			&size_p, &size_p);
	obj->img_pr = mlx_xpm_file_to_image(obj->mlx, "images/player_right.xpm",
			&size_p, &size_p);
	obj->img_pu = mlx_xpm_file_to_image(obj->mlx, "images/player_up.xpm",
			&size_p, &size_p);
	obj->img_pd = mlx_xpm_file_to_image(obj->mlx, "images/player_down.xpm",
			&size_p, &size_p);
}

void	assign_nbr(t_game *obj)
{

}
