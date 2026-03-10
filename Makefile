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

INPUT1:=$(shell seq 0 2 | sort -R)
INPUT2:=$(shell seq -4 0 | sort -R)
INPUT3:=$(shell seq 0 9 | sort -R)
INPUT4:=$(shell seq -50 49 | sort -R)
INPUT5:=$(shell seq -250 249 | sort -R)
INPUT6:=$(shell seq -500 499 | sort -R)
INPUT7:=$(shell seq -3 2 | sort -R)

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

check: $(NAME)
	@printf " running with 3 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT1) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 5 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT2) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 10 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT3) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 100 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT4) | ./checker_linux $(INPUT4)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT4) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 500 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT5) | ./checker_linux $(INPUT5)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT5) | wc -l | tr -d "[:blank:]"
	@printf "\n check correctness... \t"
	@./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)
	@./$(NAME) $(INPUT4) | ./checker_linux $(INPUT4)
	@./$(NAME) $(INPUT5) | ./checker_linux $(INPUT5)

small_check: $(NAME)
	@printf " running with 3 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT1) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 5 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT2) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 6 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT7) | ./checker_linux $(INPUT7)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT7) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 10 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT3) | wc -l | tr -d "[:blank:]"
	@printf "\n check correctness... \t"
	@./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@./$(NAME) $(INPUT7) | ./checker_linux $(INPUT7)
	@./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)


.PHONY: all bonus clean fclean re