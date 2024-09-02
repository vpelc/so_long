# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 22:13:20 by vpelc             #+#    #+#              #
#    Updated: 2024/09/02 19:47:17 by vpelc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME                = so_long

# Directories
INC                 = include/
SRC_DIR             = src/
OBJ_DIR             = obj/
GNL_DIR             = get_next_line/

# Compiler and CFlags
CC                  = cc
CFLAGS              = -Wall -Werror -Wextra -g
RM                  = rm -f

# Additional flags
INCLUDES            = -I /usr/local/include
LIBRARIES           = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

# Source files
SRCS                = main.c check_args.c check_map.c check_moves.c \
					check_possible.c get_map.c display.c moves.c utils.c
GNL_SRCS            = get_next_line.c get_next_line_utils.c

# File paths
SRC                 = $(addprefix $(SRC_DIR), $(SRCS))
GNL_SRC             = $(addprefix $(GNL_DIR), $(GNL_SRCS))
OBJ                 = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o) $(GNL_SRCS:.c=.o))

all:                $(NAME)

obj:
	@if [ -d $(OBJ_DIR) ]; then \
		echo "\033[1;31mDirectory already created.\033[0m"; \
	else \
		mkdir -p $(OBJ_DIR); \
		echo "Directory obj/ with files .o is being created..."; \
	fi

$(NAME): obj $(OBJ)
	@echo "Compiling so_long..."
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBRARIES)
	@echo "\033[1;32mDone.\033[0m"

# Compile object files from source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mFile $@ created.\033[0m";

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -I$(GNL_DIR) $(INCLUDES) -c $< -o $@
	@echo "\033[1;32mFile $@ created.\033[0m";

clean:
	@echo "Removing obj/..."
	@$(RM) -r $(OBJ_DIR)
	@echo "\033[1;32mAll Done for clean.\033[0m"

fclean: clean
	@echo "Removing so_long..."
	@$(RM) $(NAME)
	@echo "\033[1;32mDone.\033[0m"

re: fclean all

.PHONY: all obj clean fclean re