NAME = push_swap
NAME2 = checker
CC = gcc -g
SRCS = src/main.c
TEST = tests/checker.c
LIBFT = libft/libft.a

all : $(NAME2)

$(NAME2): $(SRCS) $(LIBFT) $(TEST)
	$(CC) $(SRCS) $(TEST) $(LIBFT) -o $(NAME2)
clean:
	rm -f $(NAME2)
re : clean all
.PHONY: all clean re