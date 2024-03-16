# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 16:05:35 by hakbas            #+#    #+#              #
#    Updated: 2024/03/16 22:25:58 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -g
LDFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR	=	libft/
MLX_DIR		=	mlx/
LIBFT		=	$(LIBFT_DIR)libft.a
MLX			=	$(MLX_DIR)libmlx.a
OBJ_DIR		=	obj
SRC			=	key_hook.c	image.c	init_game.c	main.c	main_utils.c map_import.c \
				map_import_utils.c	map_init.c	map_utils.c	map_valid_path.c \
				map_validity.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re