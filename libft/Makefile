# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaballe <dcaballe@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 19:44:51 by dcaballe          #+#    #+#              #
#    Updated: 2023/02/15 12:53:21 by dcaballe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isascii.c ft_memcpy.c ft_strncmp.c ft_bzero.c\
			ft_isdigit.c ft_memmove.c ft_strlcat.c ft_strrchr.c ft_tolower.c\
			ft_isalnum.c ft_isprint.c ft_memset.c ft_strlcpy.c ft_toupper.c\
			ft_isalpha.c ft_memchr.c ft_strchr.c ft_strlen.c ft_isalpha.c\
			ft_strrchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
			ft_strdup.c ft_substr.c ft_strjoin.c ft_strjoin_free.c ft_strtrim.c ft_split.c\
			ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_atol.c ft_checkdigit.c\
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_free_split.c ft_count.c\
			ft_issign.c
SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}
OBJS 	=	${SRCS:.c=.o}
NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror
RM		=	-rm -f
CC		=	gcc

all: $(NAME)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	${CC} -c ${CFLAGS} ${SRCS}
	ar crs ${NAME} ${OBJS}
bonus: $(NAME) ${OBJS_BONUS}
	ar crs ${NAME} ${OBJS_BONUS}
clean:
	${RM} ${OBJS}
	${RM} $(OBJ_BONUS)

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
