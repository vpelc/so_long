/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 15:17:22 by vpelc             #+#    #+#             */
/*   Updated: 2024/09/06 14:17:18 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h" 

# define SQUARE_SIZE 72
# define PLAYER_SIZE 81
# define SCORE_SIZE 24

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_1;
	void	*img_0;
	void	*img_e;
	void	*img_c;
	void	*img_pu;
	void	*img_pd;
	void	*img_pl;
	void	*img_pr;
	void	*nbr_0;
	void	*nbr_1;
	void	*nbr_2;
	void	*nbr_3;
	void	*nbr_4;
	void	*nbr_5;
	void	*nbr_6;
	void	*nbr_7;
	void	*nbr_8;
	void	*nbr_9;

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

void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);

int		can_up(t_map *map);
int		can_down(t_map *map);
int		can_left(t_map *map);
int		can_right(t_map *map);

void	assign_img(t_game *obj);

void	display(t_game *obj, int i, int j, char sqr_type);
void	display_player(t_game *obj, int i, int j, char sqr_type);
void	display_map(t_map *map, t_game *obj);
void	*display_numbers(t_map *map, int nbr);
void	refresh_player(t_map *map);
void	refresh_score(t_map *map);

int		close_window(t_map *map);

void	not_win(t_map *map, char dir);

void	fill_map(t_map *map);

void	check_args(int argc, char *argv[]);

void	check_map(t_map *map);

void	send_error(char *error);

int		check_possible(t_map *map);

#endif