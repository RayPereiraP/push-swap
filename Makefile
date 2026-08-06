# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/28 21:05:01 by rayperei          #+#    #+#              #
#    Updated: 2026/07/23 14:46:25 by rayperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinc

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

SRC_FILES	= main.c \
			  parser.c \
			  utils.c \
			  flags.c \
			  disorder.c \
			  free_memory.c \
			  push_swap_init.c \
			  index_array.c \
			  benchmark.c \
			  operations_swap.c \
			  operations_push.c \
			  operations_rotate.c \
			  operations_rev_rotate.c \
			  algo_simple.c \
			  algo_medium.c \
			  algo_complex.c \
			  algo_adaptive.c
			  
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re