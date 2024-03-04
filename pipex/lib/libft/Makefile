# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 23:47:16 by hakbas            #+#    #+#              #
#    Updated: 2024/03/03 15:58:05 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
FLAGS		= -Wall -Wextra -Werror
CC			= gcc
SRCS		= ft_bzero.c			\
			  ft_calloc.c			\
			  ft_lstnew.c			\
			  ft_lstadd_front.c		\
			  ft_lstsize.c			\
			  ft_lstlast.c			\
			  ft_lstadd_back.c		\
			  ft_lstdelone.c		\
			  ft_lstclear.c			\
			  ft_memcpy.c			\
			  ft_memset.c			\
			  ft_write_fd.c			\
			  ft_split.c			\
			  ft_strchr.c			\
			  ft_strdup.c			\
			  ft_strjoin.c			\
			  ft_strlcat.c			\
			  ft_strlcpy.c			\
			  ft_strlen.c			\
			  ft_strncmp.c			\
			  ft_strcmp.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
