CC := cc
CFLAGS := -Wall -Werror -Wextra -MMD -MP
AR := ar rcs

CFILES :=  src/input_check.c src/stack.c src/stack_utils.c \
           src/operations/stack_operations.c src/operations/stack_operations_utils.c \
		   src/operations/stack_operations_swap_push.c src/operations/stack_operations_rotate.c \
		   src/operations/stack_operations_double.c\
		   src/sort/sort.c src/sort/sort_basic.c src/sort/sort_radix.c src/sort/sort_3.c \
		   src/stack_clean.c
OFILES := $(CFILES:.c=.o)

GNLCFILES := includes/get_next_line/get_next_line.c includes/get_next_line/get_next_line_utils.c

GNLOFILES := $(GNLCFILES:.c=.o)

LIBFT := includes/libft

NAME = push_swap

BONUS = checker

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	gcc $(CFLAGS) push_swap.c $(OFILES) -o $(NAME) -L $(LIBFT) -l ft

bonus: $(OFILES) $(GNLOFILES)
	make -C $(LIBFT)
	gcc $(CFLAGS) checker.c $(OFILES) $(GNLOFILES) -o $(BONUS) -L $(LIBFT) -l ft

clean: 
	make clean -C $(LIBFT)
	rm -f $(OFILES)
	rm -f $(OFILES:.o=.d)
	rm -f $(NAME).d
	rm -f $(GNLOFILES)
	rm -f $(GNLOFILES:.o=.d)
	rm -f $(BONUS).d

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

-include $(OFILES:.o=.d)
-include $(GNLOFILES:.o=.d)
