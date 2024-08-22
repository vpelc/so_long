/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:17:22 by vpelc             #+#    #+#             */
/*   Updated: 2024/08/22 22:00:03 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h" 

# define pass (void)0
# define SQUARE_SIZE 64

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}	t_mlx;

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

void	write_move(t_map *map, char dir);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);

int		can_up(t_map *map);
int		can_down(t_map *map);
int		can_left(t_map *map);
int		can_right(t_map *map);

void	display(t_mlx *obj, int i, int j, char sqr_type);
void	close_window(t_mlx *obj);

t_map	read_map(t_map map);
t_map	fill_map(t_map map);

void	check_args(int argc, char *argv[]);

void	check_border(t_map map);
void	check_elem(t_map map);

void	send_error(char *error);

#endif