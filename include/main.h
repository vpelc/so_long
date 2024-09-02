/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:17:22 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/02 20:50:51 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h" 

# define SQUARE_SIZE 72
# define PLAYER_SIZE 84

typedef struct s_game
{
	void	*mlx;
	void	*win;

}	t_game;

typedef struct s_map
{
	char	*name;
	int		lines;
	int		columns;
	char	**tab;
	int		exit;
	int		player;
	int		player_pos_x;
	int		player_pos_y;
	int		collect;
	int		end;
	int		moves;
	t_game	*game;
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

void	display(t_game *obj, int i, int j, char sqr_type);
void	display_player(t_game *obj, int i, int j, char sqr_type);
void	display_map(t_map *map, t_game *obj);
void	display_first(t_map *map, t_game *game);
void	close_window(t_game *obj);

void	fill_map(t_map *map);

void	check_args(int argc, char *argv[]);

void	check_map(t_map *map);

void	send_error(char *error);

int		check_possible(t_map *map);

#endif