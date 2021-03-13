# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/12 18:48:36 by kaye              #+#    #+#              #
#    Updated: 2021/03/13 15:30:37 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC		= clang
CFLAGS 	= -Wall -Wextra -Werror
LFLAGS	= -L./libft -lft
IFLAGS 	= -I./inc

# DIRECTORIES

BUILD 			:= .build
INC_DIR 		:= inc
SRC_DIR 		:= src
SUB_DIR			:= checker \
				   push_swap \
				   utils
LFT_DIR			:= libft
OBJ_DIR 		:= $(BUILD)/obj
DIRS			:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILES

PUSH_SWAP		:= push_swap
CHECKER			:= checker
SRC				:= 
SRC_PUSH_SWAP	:= 
SRC				:= 
SRC_CHECKER		:= 
SRC				:= 
SRC_UTILS		:= 
OBJ_PUSH_SWAP	:= $(SRC_PUSH_SWAP:%.c=$(OBJ_DIR)/%.o)
OBJ_CHECKER		:= $(SRC_CHECKER:%.c=$(OBJ_DIR)/%.o)
OBJ_UTILS		:= $(SRC_UTILS:%.c=$(OBJ_DIR)/%.o)

# COLORS

DEFAULT_COLOR	= \033[0m
BLACK_COLOR		= \033[1;30m
RED_COLOR		= \033[1;31m
GREEN_COLOR		= \033[1;32m
YELLOW_COLOR	= \033[1;33m
BLUE_COLOR		= \033[1;34m
MAGENTA_COLOR 	= \033[1;35m
CYAN_COLOR 		= \033[1;36m

# MAKEFILE

$(PUSH_SWAP): $(OBJ_PUSH_SWAP) $(OBJ_CHECKER) $(OBJ_UTILS)
	@$(MAKE) -C $(LFT_DIR)
	@echo "Creating $(RED_COLOR) $(PUSH_SWAP) $(DEFAULT_COLOR)..."
	$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $(OBJ_PUSH_SWAP) $(OBJ_UTILS) -o $(PUSH_SWAP)
	@echo "Creating $(RED_COLOR) $(CHECKER) $(DEFAULT_COLOR)..."
	$(CC) $(CFLAG) $(IFLAG) $(LFLAG) $(OBJ_CHECKER) $(OBJ_UTILS) -o $(CHECKER)

all: $(PUSH_SWAP)

clean:
	@$(MAKE) -C $(LFT_DIR) clean
	rm -Rf $(BUILD)
fclean: clean
	@$(MAKE) -C $(LFT_DIR) fclean
	rm -Rf $(PUSH_SWAP)
	rm -Rf $(CHECKER)

re: fclean all

.PHONY: all clean fclean re

$(BUILD):
	@echo "Creating $(RED_COLOR)$@ $(DEFAULT_COLOR)..."
	@mkdir -p $@ $(DIRS)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD)
	@echo "Compiling $(CYAN_COLOR)$< $(DEFAULT_COLOR)..."
	@$(CC) $(CFLAG) $(IFLAG) -c $< -o $@
