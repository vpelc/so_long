/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:33:56 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/04 23:02:12 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	assign_numbers(t_game *obj)
{
	int	size;

	size = SCORE_SIZE;
	obj->nbr_0 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_0.xpm",
			&size, &size);
	obj->nbr_1 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_1.xpm",
			&size, &size);
	obj->nbr_2 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_2.xpm",
			&size, &size);
	obj->nbr_3 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_3.xpm",
			&size, &size);
	obj->nbr_4 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_4.xpm",
			&size, &size);
	obj->nbr_5 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_5.xpm",
			&size, &size);
	obj->nbr_6 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_6.xpm",
			&size, &size);
	obj->nbr_7 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_7.xpm",
			&size, &size);
	obj->nbr_8 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_8.xpm",
			&size, &size);
	obj->nbr_9 = mlx_xpm_file_to_image(obj->mlx, "images/nbr_9.xpm",
			&size, &size);
}


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
	assign_numbers(obj);
}

char	*path_to_img_alpha(char c)
{
	char	*join;
	char	*start;
	char	*end;

	start = "images/alpha_";
	end = ".xpm";
	join = malloc(sizeof(char) * 1);
	join[0] = c;
	ft_strjoin(start, join);
	ft_strjoin(join, end);
	return (join);
}

void	assign_alpha(t_game *obj, char c)
{
	void	*img;
	int		size;

	size = SCORE_SIZE;
	img = mlx_xpm_file_to_image(obj->mlx, path_to_img_alpha(c),
			&size, &size);
	mlx_put_image_to_window(obj->mlx, obj->win, img, 8, 8);
}
