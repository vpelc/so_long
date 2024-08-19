/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:17:22 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/19 16:52:51 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h" 

# define pass (void)0

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