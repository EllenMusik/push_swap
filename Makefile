NAME= push_swap.a
CC = gcc
#CFLAGS= -Wall -Werror -Wextra
DEBUG = -fsanitize=address -g
HEADER= push_swap.h
RM= rm -rf
NAME = push_swap

LIBFT= libft/libft.a
OBJ_DIR= obj

FILES=	push_swap.c push_swap_help.c operations/pushing.c \
		operations/swapping.c operations/rotating.c operations/reverse_rotating.c \
		sorting.c getting_the_index.c sorting_3_and_5.c cost_calculate.c \

O_FILES= $(FILES:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) bonus -C libft
	$(CC) $(CFLAGS) $(DEBUG) $(O_FILES) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ_DIR)
	
fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re