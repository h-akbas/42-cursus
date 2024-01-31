# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halilakbas <halilakbas@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 17:56:24 by ugerkens          #+#    #+#              #
#    Updated: 2024/01/02 00:07:23 by halilakbas       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= ft_printf.a
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -Isrc -Iinclude

# Paths and Files
VPATH		= src
SRCS		= ft_printf.c ft_print_nbr.c

OBJS		= $(addprefix obj/, $(SRCS:.c=.o))

# Rules
$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

obj:
			mkdir -p obj

obj/%.o:	%.c | obj
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			$(RM) obj

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.SILENT:

.PHONY:		all clean fclean re
