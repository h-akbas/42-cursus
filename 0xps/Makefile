# Variables
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc -O3 -g3
RM					=	rm -rf
PUSH_SWAP			=	push_swap
NAME				=	$(PUSH_SWAP)

# Libraries
LIBFT				=	libft.a
LIBFT_DIR			=	libraries/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

FT_PRINTF			=	ft_printf.a
FT_PRINTF_DIR		=	libraries/ft_printf
FT_PRINTF_FILE		=	$(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
VPATH				=	srcs:srcs/mandatory:
PUSH_SWAP_INC		=	push_swap.h
PUSH_SWAP_SRC		=	both_stack.c free.c init.c list.c  \
						parsing.c push_swap.c sorting.c \
						sorting2.c stack_a.c stack_b.c utils.c \

# Rules
all:				$(PUSH_SWAP)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_FILE) $(FT_PRINTF_FILE)
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c $(PUSH_SWAP_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ):		obj/checker/%.o: %.c $(CHECKER_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)
$(FT_PRINTF_FILE):
					$(MAKE_LIB) $(FT_PRINTF_DIR)

$(PUSH_SWAP):		$(LIB) $(PUSH_SWAP_OBJ)
					$(CC) $(CFLAGS) $(LIB) $(PUSH_SWAP_OBJ) -o $@


lib_clean:
					$(MAKE_LIB) $(LIBFT_DIR) clean
					$(MAKE_LIB) $(FT_PRINTF_DIR) clean

lib_fclean:
					$(MAKE_LIB) $(LIBFT_DIR) fclean
					$(MAKE_LIB) $(FT_PRINTF_DIR) fclean

clean:				lib_clean
					$(RM) obj

fclean:				clean lib_fclean
					$(RM) $(NAME)

re:					fclean all

.SILENT:

.PHONY:				all lib_clean lib_fclean clean fclean re