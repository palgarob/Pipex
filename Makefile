# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 16:42:54 by pepaloma          #+#    #+#              #
#    Updated: 2023/12/22 17:10:17 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= libft
SRC_DIR		= src
OBJ_DIR		= obj
BIN_DIR		= bin

NAME		= $(BIN_DIR)/pipex

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
LIBFT_LINK_FLAGS= -I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft
VALGRIND_FLAGS	= -O0 -g

FILES	= $(notdir $(wildcard src/*.c))
SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

.PHONY : all re clean fclean

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBFT_LINK_FLAGS) $(VALGRIND_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(VALGRIND_FLAGS) -c $< -o $@

fclean : clean
	$(RM) $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

clean :
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

re : fclean all
