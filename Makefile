NAME = push_swap
NAME2 = checker
CC = gcc -g
SRCS = src/make_array.c src/sort_array.c src/make_stacks.c src/push_swap.c \
		src/stack_utils.c src/position.c src/error.c src/utils.c src/moves.c\
		src/organize_stack.c
MAIN = src/main.c
TEST = tests/checker.c
LIBFT = libft/libft.a

all : $(NAME)
test: $(NAME2)
$(NAME2): $(TEST) $(SRCS) $(LIBFT)
	$(CC) $(SRCS) $(TEST) $(LIBFT) -o $(NAME2)
$(NAME): $(SRCS) $(MAIN) $(LIBFT)
	$(CC) $(SRCS) $(MAIN) $(LIBFT) -o $(NAME)
clean:
	rm -f $(NAME)
re : clean all
retest: 
	rm -f $(NAME2) 
	make test
.PHONY: all clean re retest test