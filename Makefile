NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c ft_split.c get_sorted_stack_in_array.c init_a.c push.c \
      reverse_rotatate.c rotate.c sort_stack.c stack_init.c stack_init2.c \
      stack_utils.c swap.c three_sort.c error_manager.c args_verif.c stack_init_utils.c

BONUS_SRC = checker_bonus.c\
			/checker/push_bonus.c /checker/reverse_rotatate_bonus.c \
			/checker/rotate_bonus.c /checker/stack_init_bonus.c /checker/stack_init2_bonus.c \
			/checker/stack_utils_bonus.c /checker/swap_bonus.c /checker/error_manager_bonus.c \
			/checker/args_verif_bonus.c /checker/stack_init_utils_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o checker/checker

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus