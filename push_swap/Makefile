# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 11:22:09 by hakbas            #+#    #+#              #
#    Updated: 2024/02/18 23:52:37 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = op_push.c \
       op_reverse_r.c \
       op_rotate.c \
       op_swap.c \
       parse_data.c \
       push_swap.c \
       push_swap_utils.c \
       sort.c \
       sort_check.c \
       sort_check_a.c \
       sort_do.c \
       sort_rotation.c \
       sort_three.c \
       split_args.c \
       stack_get_utils.c \
       stack_init_utils.c \
       stack_misc_utils.c

OBJS = $(patsubst %.c,objs/%.o,$(SRCS))
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: objs $(TARGET)

objs:
	mkdir -p objs

$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $@

objs/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf objs

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(TARGET)

re: fclean all

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(TARGET)

.PHONY: all clean fclean re
