# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 07:36:55 by hakbas            #+#    #+#              #
#    Updated: 2024/01/30 08:27:43 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_FILES = arg.h arg_split.c arg_validity.c \
			op_push.c op_reverse.c op_rotate.c ops.h op_swap.c op_utils.c \
			ps_utils.c push_swap.c push_swap.h \
			sort.c sort.h sort_mgmt.c sort_utils.c \
			stack.h stack_init.c stack_table.c stack_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)
TARGET = push_swap

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -v $(OBJ_FILES)

fclean: clean
	rm -v $(TARGET)

re: fclean all

debug: CFLAGS += -g
debug: re

sanitize: CFLAGS += -fsanitize=address
sanitize: re

.PHONY: all clean fclean re debug sanitize
