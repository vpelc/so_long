# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 22:13:20 by vpelc             #+#    #+#              #
#    Updated: 2024/05/31 22:25:06 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -rf

SOURCES = 

OBJECTS = ${SOURCES:.c=.o}

all = ${NAME}

${NAME}:	${OBJECTS}
		${AR} ${NAME} ${OBJECTS}

.c.o:
		${CC} -c $< -o ${<:.c=.o} -I ./

clean:
		${RM} ${OBJECTS} 

fclean:		clean
		${RM} ${NAME} 

re:		fclean all
	
.PHONY: all clean fclean re