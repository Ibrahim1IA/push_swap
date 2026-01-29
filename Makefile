NAME = push_swap
BONUS_NAME = checker
CC = gcc
CFLAGS = -Wall

SRC = push_swap.c ft_split.c get_sorted_stack_in_array.c init_a.c push.c \
      reverse_rotatate.c rotate.c sort_stack.c stack_init.c stack_init2.c \
      stack_utils.c swap.c three_sort.c error_manager.c args_verif.c stack_init_utils.c

BONUS_SRC = checker_files/checker_bonus.c checker_files/checker_utils_bonus.c \
			checker_files/push_bonus.c checker_files/reverse_rotatate_bonus.c \
			checker_files/rotate_bonus.c checker_files/stack_init_bonus.c checker_files/stack_init2_bonus.c \
			checker_files/stack_utils_bonus.c checker_files/swap_bonus.c checker_files/error_manager_bonus.c \
			checker_files/args_verif_bonus.c checker_files/ft_split_bonus.c \
			checker_files/get_next_line/get_next_line.c checker_files/get_next_line/get_next_line_utils.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

./checker_files/%.o : ./checker_files/%.c checker_files/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus