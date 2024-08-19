# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 22:13:20 by vpelc             #+#    #+#              #
#    Updated: 2024/08/19 16:30:11 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc 

MLXFLAGS = 

RM = rm -rf

SOURCES = main.c 

OBJECTS = ${SOURCES:.c=.o}

all = ${NAME}

${NAME}:	${OBJECTS}
		$(CC) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I ./

%.o: %.c
		$(CC) -I./ -Imlx -c $< -o $@

clean:
		${RM} ${OBJECTS} 

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re