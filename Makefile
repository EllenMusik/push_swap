NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address -g

RM = rm -rf

LIBFT = libft/libft.a

OBJ_DIR = obj

COMMON_SRC = push_swap_help.c \
	sorting.c \
	getting_the_index.c \
	sorting_3_and_5.c \
	cost_calculate.c \
	find_target_position.c \
	execute_lowest_cost.c

SRC = push_swap.c \
	operations/pushing.c \
	operations/swapping.c \
	operations/rotating.c \
	operations/reverse_rotating.c \
	$(COMMON_SRC)

BONUS_SRC = bonus/checker.c \
	bonus/operations/pushing.c \
	bonus/operations/swapping.c \
	bonus/operations/rotating.c \
	bonus/operations/reverse_rotating.c \
	bonus/execute_instructions.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	$(COMMON_SRC)

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(DEBUG) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re