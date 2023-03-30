NAME = push_swap
CC = gcc -g
SRCS = src/make_array.c src/sort_array.c src/make_stacks.c src/push_swap.c \
		src/stack_utils.c src/position.c src/error.c src/utils.c src/moves.c\
		src/organize_stack.c src/main.c
OBJS = $(SRCS:.c=.o)
MAIN = src/main.c
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
$(LIBFT):
	make -C libft
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re : fclean all
libclean:
	make -C ./libft fclean
.PHONY: all clean re fclean libclean