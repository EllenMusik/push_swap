NAME= push_swap.a
CC = gcc
CFLAGS= -Wall -Werror -Wextra
DEBUG = -fsanitize=address -g
HEADER= push_swap.h
RM= rm -rf
NAME = push_swap

LIBFT= libft/libft.a

FILES=	push_swap.c push_swap_help.c pushing.c swapping.c rotating.c reverse_rotating.c sorting.c input_check.c sorting_3_and_5.c

O_FILES= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) bonus -C libft
	$(CC) $(CFLAGS) $(DEBUG) $(O_FILES) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C libft
	$(RM) $(O_FILES)
	
fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re