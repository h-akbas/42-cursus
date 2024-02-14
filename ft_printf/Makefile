NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCF =  ft_printf.c ft_putnbr.c ft_putchar.c ft_putstr.c \
		ft_printunbr.c ft_puthexa.c ft_putptr.c

OBJ = $(SRCF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ) $(NAME)

re: fclean all 

.PHONY: clean