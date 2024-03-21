# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 22:49:42 by hakbas            #+#    #+#              #
#    Updated: 2024/03/17 23:46:35 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		fractol
CC			=		gcc
CFLAGS		=		-Wall -Wextra -Werror -g -fsanitize=address
SRC			=		main.c		fractol.c		hooks.c		instr.c		\
					color.c		hook_utils.c	mandelbrot.c			\
					mlx_utils.c		utils.c		burning_ship.c julia.c	
OBJ			=		$(SRC:.c=.o)
UNAME_S		=		$(shell uname -s)
ifeq ($(UNAME_S), Linux)
MLX			=		./mlx-linux
MLX_LIB		=		-L $(MLX) -lmlx -lXext -lx11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
MLX			=		./mlx-macos
MLX_LIB		=		-L $(MLX) -lmlx -framework OpenGL -framework AppKit -fsanitize=address
endif

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLX_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re