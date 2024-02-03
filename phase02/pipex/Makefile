# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 15:28:27 by hakbas            #+#    #+#              #
#    Updated: 2024/02/03 16:37:49 by hakbas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET		= pipex
TARGET_B  	= pipex_bonus

SRCS 		= pipex.c pipex_utils.c
OBJS 		= ${SRCS:.c=.o}
MAIN		= pipex.c

SRCS_B		= pipex_bonus.c utils.c utils_bonus.c
OBJS_B		= ${SRCS_B:.c=.o}
MAIN_B		= pipex_bonus.c


CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g

.c.o:		%.o : %.c
					@gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all: 		${TARGET}

${TARGET}:	${OBJS}
					@make re -C ./libft
					@$(CC) ${OBJS} -Llibft -lft -o ${TARGET}


bonus:		${TARGET_B}

${TARGET_B}:	${OBJS_B}
					@make re -C ./libft
					@$(CC) ${OBJS_B} -Llibft -lft -o ${TARGET_B}

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f ${TARGET}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus party
