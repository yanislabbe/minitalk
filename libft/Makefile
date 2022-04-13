# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 14:27:30 by ylabbe            #+#    #+#              #
#    Updated: 2021/10/12 14:50:22 by ylabbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_strdup.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_substr.c ft_strjoin.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_memchr.c ft_calloc.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strnstr.c ft_memcmp.c ft_atoi.c ft_toupper.c \
	ft_tolower.c ft_strncmp.c ft_memset.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c

BONUS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS := ${SRCS:.c=.o}
OBJS_BONUS := ${BONUS:.c=.o}

NAME := libft.a
CC := gcc
AR := ar rcs
RM := rm -f
CFLAGS := -Wall -Werror -Wextra -I.

all: ${NAME}

%.o: %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

norme:
	norminette

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: ${OBJS} ${OBJS_BONUS}
		${AR} ${NAME} ${OBJS} ${OBJS_BONUS}

.PHONY: all clean fclean re
