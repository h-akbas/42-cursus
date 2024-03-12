# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 21:34:47 by hakbas            #+#    #+#              #
#    Updated: 2024/03/12 22:15:38 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
SRC_DIR			=	src
OBJ_DIR			=	obj
INC_DIR			=	inc
ASSETS_DIR		=	assets
LIBFT_DIR		=	libs/libft
MLX_MAC_DIR		=	libs/mlx-macos
MLX_LINUX_DIR	=	libs/mlx-linux
GNL_DIR			=	libs/get_next_line
FTPRINTF_DIR	=	libs/ft_printf
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-I$(INC_DIR) -I$(LIBFT_DIR)/inc
CFLAGS			+=	-g
LD_MAC			=	-Lmlx-macos -lmlx -framework OpenGL -framework AppKit -lm
LD_LINUX		=	-Lmlx-macos -lmlx -lXext -lX11 -lm

ifeq				($(shell uname), Linux)
	LD_FLAGS	=	$(LD_LINUX)
	LIB_MLX_DIR	=	$(MLX_LINUX)
	LIB_MLX		=	$(MLX_LINUX)/libmlx.a
else ifeq			($(shell uname), Darwin)
	LD_FLAGS	=	$(LD_MAC)
	LIB_MLX_DIR	=	$(MLX_MAC)
	LIB_MLX		=	$(MLX_MAC)/libmlx.a
endif

BUILD_LIBFT		=	make -C $(LIBFT_DIR)
BUILD_MLX		=	make -C $(LIB_MLX_DIR)
BUILD_GNL		=	make -C $(GNL_DIR)
BUILD_FTPRINTF	=	make -C $(FTPRINTF_DIR)
BUILD_LIBS		=	$(BUILD_LIBFT) $(BUILD_MLX) $(BUILD_GNL) $(BUILD_FTPRINTF)

SRC				=	main.c		error.c		init.c			\
								map.c						\
					player.c	collectible.c	exit.c		\
					render.c	utils.c			events.c	\
					free.c

INC				=	so_long.h	events.h		map.h		\
					gfx.h		obj.h						\

OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJ) $(LIB_MLX) $(LIBFT_DIR)/libft.a $(GNL_DIR)/get_next_line.a $(FTPRINTF_DIR)/libftprintf.a
				$(CC) $(CFLAGS) $(LD_FLAGS) -o $@ $(OBJ) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lget_next_line -L$(FTPRINTF_DIR) -lftprintf


re:				fclean all

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

