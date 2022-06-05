CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar rcs

CFILES := push_swap.c src/input_check.c src/stack.c src/stack_utils.c \
           src/operations/stack_operations.c src/operations/stack_operations_utils.c \
		   src/operations/stack_operations_swap_push.c src/operations/stack_operations_rotate.c \
		   src/operations/stack_operations_double.c\
		   src/sort/sort.c src/sort/sort_basic.c src/sort/sort_radix.c src/sort/sort_3.c
OFILES := $(CFILES:.c=.o)

LIBFT := includes/libft

NAME = push_swap.a

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OFILES)
	gcc $(CFLAGS) $(NAME)  -o push_swap

clean: 
	make clean -C $(LIBFT)
	rm -f $(OFILES)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.SILENT:
#-fsanitize=address