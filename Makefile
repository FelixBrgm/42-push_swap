CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP
AR := ar rcs

CFILES := push_swap.c src/input_check.c src/stack.c src/stack_utils.c \
           src/operations/stack_operations.c src/operations/stack_operations_utils.c \
		   src/operations/stack_operations_swap_push.c src/operations/stack_operations_rotate.c \
		   src/operations/stack_operations_double.c\
		   src/sort/sort.c src/sort/sort_basic.c src/sort/sort_radix.c src/sort/sort_3.c \
		   src/stack_clean.c
OFILES := $(CFILES:.c=.o)

LIBFT := includes/libft

NAME = push_swap

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	gcc $(CFLAGS) $(OFILES) -o $(NAME) -L $(LIBFT) -l ft

clean: 
	make clean -C $(LIBFT)
	rm -f $(OFILES)
	rm -f $(OFILES:.o=.d)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

-include $(OFILES:.o=.d)
