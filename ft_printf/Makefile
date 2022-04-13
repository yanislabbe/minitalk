# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:28:24 by ylabbe            #+#    #+#              #
#    Updated: 2022/04/04 23:02:37 by ylabbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_libft.c

OBJS = $(SRCS:.c=.o)

NAME = ft_printf.a
CC = gcc -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rfd

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
