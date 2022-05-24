CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar rcs

CFILES := push_swap.c src/check_input.c src/stack.c src/stack_operations.c
OFILES := $(CFILES:.c=.o)

LIBFT := includes/libft

NAME = push_swap.a

all: $(NAME)

$(NAME): $(OFILES)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $(NAME) $(OFILES)
	gcc $(CFLAGS) $(NAME) -o push_swap

clean: 
	make clean -C $(LIBFT)
	rm -f $(OFILES)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.SILENT: