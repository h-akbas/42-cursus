# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 21:34:47 by hakbas            #+#    #+#              #
#    Updated: 2024/03/12 23:23:57 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME		= so_long

# Directories
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
ASSETS_DIR	= assets
LIBFT_DIR	= libs/libft
MLX_MAC_DIR	= libs/mlx_macos
MLX_LINUX_DIR= libs/mlx_linux
GNL_DIR		= libs/get_next_line
FTPRINTF_DIR= libs/ft_printf

# Compiler and flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/inc -g

# Source and Object Files
SRC			= main.c # error.c init.c map.c player.c collectible.c exit.c render.c utils.c events.c free.c
OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

# Libraries and Linking Flags
LD_FLAGS	= -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lget_next_line -L$(FTPRINTF_DIR) -lftprintf

# Determine OS and adjust linking flags accordingly
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LD_FLAGS += -L$(MLX_LINUX_DIR) -lmlx -lXext -lX11 -lm
	LIB_MLX_DIR = $(MLX_LINUX_DIR)
endif
ifeq ($(UNAME_S),Darwin)
	LD_FLAGS += -L$(MLX_MAC_DIR) -lmlx -framework OpenGL -framework AppKit
	LIB_MLX_DIR = $(MLX_MAC_DIR)
endif

# Phony Targets
.PHONY: all clean fclean re test leaks debug norm maps

# Default target
all: $(NAME)

# Linking the executable
$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(LIB_MLX_DIR)
	$(CC) $(OBJ) $(LD_FLAGS) -o $@

# Compiling object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create obj directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)

# Full clean (includes executable)
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

test:			all
				./$(NAME) $(ASSETS_DIR)/map.ber

leaks:			all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ASSETS_DIR)/map.ber

debug:			all
				lldb ./$(NAME) $(ASSETS_DIR)/map.ber

norm:
				norminette $(SRC_DIR) $(INC_DIR)

maps:
				@echo "Available maps:"
				@ls -1 $(ASSETS_DIR) | grep .ber

.PHONY:			all clean fclean re test leaks debug norm maps

