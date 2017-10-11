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

NAME = lem_in

SRC_PATH = ./

SRC_NAME =	lem_in.c \
			add_rooms.c \
			add_tubes.c \
			find_way.c \
			tools.c \
			cleaner.c

OBJ_NAME = $(SRC_NAME:.c=.o)

LIB_NAME = libft.a

LIB_PATH =  libft/

OBJ_PATH = ./obj/

CC = gcc

W_FLAGS = -Werror -Wall -Wextra -g

I_FLAGS = -I includes

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -c $(SRC) $(I_FLAGS) $(W_FLAGS)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all