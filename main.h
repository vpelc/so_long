/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:17:22 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/15 16:25:33 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <fcntl.h>
#include <unistd.h>
#include "mlx_linux/mlx.h"
#include "GNL/get_next_line.h" 

#define pass (void)0

typedef struct s_object
{
	void	*mlx_ptr;
	void	*win_ptr;

}	t_object;

typedef struct s_map
{
	char	*name;
	int		lines;
	int		columns;
	char	**tab;
	int		exit;
	int		player;
	int		player_pos[2];
	int		collect;
	int		end;
}	t_map;

typedef struct s_map_copy
{
	int		collect;
	int		exit;
	t_map	*map;
}	t_map_copy;

#endif