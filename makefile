# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:15 by jpascal           #+#    #+#              #
#    Updated: 2017/05/22 19:18:27 by jpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# EXECUTABLE

NAME 			= lem-in

# PATHS

SRCS_PATH 		= ./src/

INC_PATH		= ./includes/

OBJ_PATH		= ./obj/

LIB_PATH 		=  ./libft/

#SOURCES

SRC_NAME =	$(SRCS_PATH)lem_in.c \
			$(SRCS_PATH)add_rooms.c \
			$(SRCS_PATH)add_tubes.c \
			$(SRCS_PATH)find_way.c \
			$(SRCS_PATH)tools.c \
			$(SRCS_PATH)cleaner.c \


LIB				= libft/libft.a

#OBJECTS

OBJ_NAME = $(SRC_NAME:$(SRCS_PATH)%.c=$(OBJ_PATH)%.o)


# COMPILATION

CC 				= clang

W_FLAGS 		= -Werror -Wall -Wextra -g3

I_FLAGS 		= -I$(INC_PATH)

#COLORS

GREEN			= "\033[0;32m"
EOC				= "\033[0;0m"
RED				= "\033[0;31m"

# COMMANDS

.PHONY: all clean fclean re
.SILENT:

all: checkpath $(NAME)

$(OBJ_PATH)%.o : $(SRCS_PATH)%.c
	$(CC) $(W_FLAGS) -c $< -o $@ $(I_FLAGS)
	echo "["$(GREEN)"√"$(EOC)"]" $@

checkpath:
	test -d $(OBJ_PATH) || mkdir $(OBJ_PATH)

$(NAME): $(OBJ_NAME)
	make -C $(LIB_PATH)
	$(CC) $(W_FLAGS) -o $(NAME) $(OBJ_NAME) $(LIB) $(I_FLAGS)
	echo $(GREEN)"LEM_IN SUCCESSFULLY COMPILED"$(EOC)

clean:
	make clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH)
	echo $(RED)"ALL OBJECTS DELETED"$(EOC)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -rf $(NAME) 
	echo $(RED)"EXEC DELETED"$(EOC) 

re: fclean 
	@$(MAKE) all