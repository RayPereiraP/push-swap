# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/28 21:05:01 by rayperei          #+#    #+#              #
#    Updated: 2026/08/08 20:22:59 by wgolbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinc

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
PRINTF_DIR  = ft_printf

SRC_FILES	= main.c \
			parser.c \
			utils.c \
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

PRINTF 		= $(PRINTF_DIR)/libftprintf.a

OBJS		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(PRINTF) $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
