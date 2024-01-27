NAME			=	push_swap
NAME_B			=	checker
LIBFT			=	libft.a libftprintf.a
DIR_SRCS		=	srcs/mandatory
DIR_BONUS		=	srcs/bonus
DIR_OBJS		=	objs
SRCS_NAMES		=	both_stack.c \
					parsing.c \
					push_swap.c \
					stack_a.c \
					stack_b.c \
					list.c \
					sorting.c \
					utils.c \
					free.c \
					init.c \
					sorting2.c

SRCS_NAMES_B	=	checker.c \
					get_next_line_utils.c \
					get_next_line.c \
					both_stack_bonus.c \
					parsing.c \
					stack_a_bonus.c \
					stack_b_bonus.c \
					list.c \
					utils_bonus.c \
					free.c \
					push_swap_bonus.c \

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}
OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}
SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))
SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))
OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))
OBJS_B			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES_B))
HEAD			=	-Ilibft/includes -Iincludes
CC				=	cc
CFLAGS			=	-g3 -Wall -Werror -Wextra
MAKEFLAGS		=	--no-print-directory

all: ${NAME}

${NAME}: $(OBJS)
	@make -C libft
	@make -C libft/ft_printf
	@cp libft/ft_printf/libftprintf.a .
	@cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} ${HEAD} -o $(NAME)
	@echo "\033[34;5mpush_swap mandatory\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

bonus: ${NAME_B}

${NAME_B}: $(OBJS_B)
	@make -C libft
	@make -C libft/ft_printf
	@cp libft/ft_printf/libftprintf.a .
	@cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS_B) ${LIBFT} ${HEAD} -o $(NAME_B)
	@echo "\033[39;5mpush_swap bonus\033[0m"

$(DIR_OBJS)/%.o: $(DIR_BONUS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)

clean:
	@make clean -C libft
	@make clean -C libft/ft_printf
	@rm -rf ${DIR_OBJS}

fclean:	clean
	@make fclean -C libft
	@make fclean -C libft/ft_printf
	@rm -rf ${LIBFT}
	@rm -rf ${NAME}
	@rm -rf ${NAME_B}

re:	fclean all

.PHONY:	all clean fclean re bonus
