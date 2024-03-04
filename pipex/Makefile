# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/03 15:21:35 by hakbas            #+#    #+#              #
#    Updated: 2024/03/03 15:40:35 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			+=	-g -Iinclude -Isrc -Ofast
RM				=	rm -rf
PIPEX			=	$(NAME)
NAME			=	pipex

# Libraries

LIBFT			=	libft.a
LIBFT_DIR		=	lib/libft
LIBFT_FILE		=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS			+=	-I $(LIBFT_DIR)

GET_NEXT_LINE	=	get_next_line.a
GNL_DIR			=	lib/get_next_line
GNL_FILE		=	$(GNL_DIR)/$(GET_NEXT_LINE)
CFLAGS			+=	-I $(GNL_DIR)

LIB				=	$(LIBFT_FILE) $(GNL_FILE)
MAKE_LIB		=	make --no-print-directory -C

# Source and Object Files

VPATH			=	include:src:src_bonus

PIPEX_INC		=	pipex.h
PIPEX_SRC		=	main.c init_data.c \
					parse_cmd.c parse_cmd_utils.c \
					in_out_file.c \
					exe_pipeline.c exe_bin_path.c \
					syscall_file.c syscall_process.c \
					error.c allocation.c
PIPEX_OBJ		=	$(PIPEX_SRC:%.c=build/%.o)

BONUS_SRC		=	main_bonus.c init_data_bonus.c \
					parse_cmd_bonus.c parse_cmd_utils_bonus.c \
					in_out_file_bonus.c \
					exe_pipeline_bonus.c exe_bin_path_bonus.c \
					syscall_file_bonus.c syscall_process_bonus.c \
					error_bonus.c allocation_bonus.c
BONUS_OBJ		=	$(BONUS_SRC:%.c=build/%.o)

# Rules

all:				lib $(PIPEX)

bonus:			$(BONUS_OBJ)
				@$(MAKE) O_OBJS="$(BONUS_OBJ)" all
O_OBJS		=	$(PIPEX_OBJ)

$(PIPEX_OBJ):	build/%.o: %.c $(PIPEX_INC)
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ):	build/%.o: %.c $(PIPEX_INC)
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

lib:
				$(MAKE_LIB) $(LIBFT_DIR)
				$(MAKE_LIB) $(GNL_DIR)

$(PIPEX):		$(LIB) $(O_OBJS)
				$(CC) $(CFLAGS) $(O_OBJS) -o $@ -L$(LIBFT_DIR) -L$(GNL_DIR) $(GNL_FILE) -lft





lib_clean:
				$(MAKE_LIB) $(LIBFT_DIR) clean
				$(MAKE_LIB) $(GNL_DIR) clean

lib_fclean:
				$(MAKE_LIB) $(LIBFT_DIR) fclean
				$(MAKE_LIB) $(GNL_DIR) fclean

clean:			lib_clean
				$(RM) build

fclean:			clean lib_fclean
				$(RM) $(PIPEX)

re:				fclean all

.SILENT:

.PHONY:			all bonus lib lib_clean lib_fclean clean fclean re
