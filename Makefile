# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 22:13:20 by vpelc             #+#    #+#              #
#    Updated: 2024/08/27 15:51:24 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc 

MLXFLAGS = 

RM = rm -rf

SOURCES = main.c check_args.c check_map.c \
			check_moves.c check_possible.c \
			get_map.c mlx_utils.c moves.c utils.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
OBJECTS = ${SOURCES:.c=.o}

all = ${NAME}

${NAME}:	${OBJECTS}
		$(CC) $(OBJECTS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I ./

%.o: %.c
		$(CC) -g -I./ -Imlx -c $< -o $@

clean:
		${RM} ${OBJECTS} 

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re