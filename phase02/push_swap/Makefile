# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 16:48:55 by hakbas            #+#    #+#              #
#    Updated: 2024/02/11 10:43:50 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3
DFLAGS = -g
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
       stack_get_utils.c \
       stack_init_utils.c \
       stack_misc_utils.c

OBJS = $(SRCS:.c=.o)
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(TARGET)

re: fclean all

debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(TARGET)

.PHONY: all clean fclean re debug
