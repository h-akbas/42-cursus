# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 11:19:26 by hakbas            #+#    #+#              #
#    Updated: 2024/02/14 11:19:27 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = ft_isdigit.c ft_split.c ft_strlcpy.c ft_strlen.c
OBJS = $(patsubst %.c,objs/%.o,$(SRCS))

all: objs ${NAME}

objs:
	mkdir -p objs

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

objs/%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -rf objs

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
