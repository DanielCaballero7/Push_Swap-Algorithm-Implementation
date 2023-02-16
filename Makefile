NAME = push_swap
NAME2 = checker
CC = gcc -g
SRCS = src/main.c
TEST = tests/checker.c
LIBFT = libft/libft.a

all : $(NAME)

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)
clean:
	rm -f $(NAME)
re : clean all
.PHONY: all clean re