# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 22:47:33 by ylabbe            #+#    #+#              #
#    Updated: 2022/04/11 16:55:53 by ylabbe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***** SOURCES  DE LIBFT **************************************************** #
LIBFT = cd libft && make
LIBFT_A = libft/libft.a

# ***** SOURCES DE FT_PRINTF ************************************************* #
FT_PRINTF = cd ft_printf && make
FT_PRINTF_A = ft_printf/ft_printf.a

# ***** SOURCES DU CLIENT **************************************************** #
CLIENTS = client.c
CLIENT_SOURCES = $(CLIENTS)
CLIENT_OBJETS = $(CLIENT_SOURCES:.c=.o)
CLIENT_NAME = client

# ***** SOURCES DU SERVEUR *************************************************** #
SERVERS = server.c
SERVER_SOURCES = $(SERVERS)
SERVER_OBJETS = $(SERVER_SOURCES:.c=.o)
SERVER_NAME = server

# ***** OBJETS DU CLIENT ET DU SERVEUR *************************************** #
OBJETS = $(CLIENT_OBJETS) $(SERVER_OBJETS)

# ***** SOURCES BONUS DU CLIENT ********************************************** #
BONUS_CLIENT = client_bonus.c
BONUS_CLIENT_SOURCES = $(BONUS_CLIENT)
BONUS_CLIENT_OBJETS = $(BONUS_CLIENT_SOURCES:.c=.o)

# ***** SOURCES BONUS DU SERVEUR ********************************************* #
BONUS_SERVER = server_bonus.c
BONUS_SERVER_SOURCES = $(BONUS_SERVER)
BONUS_SERVER_OBJETS = $(BONUS_SERVER_SOURCES:.c=.o)

# ***** COMPILATION ********************************************************** #
GCC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = server
AR = ar rcs

# ***** RÈGLES *************************************************************** #
all: $(NAME)
	@echo "\033[92mMinitalk par Yanis Labbé\033[0m"
	@echo "\033[92mFenêtre 1: ./server\033[0m"
	@echo "\033[92mFenêtre 2: ./client pid msg\033[0m"

$(NAME): libfta ft_printfa client

libfta:
	$(LIBFT)

ft_printfa:
	$(FT_PRINTF)

server: $(SERVER_OBJETS)
	$(GCC) $(FLAGS) $(SERVER_OBJETS) $(LIBFT_A) $(FT_PRINTF_A) -o $(SERVER_NAME)

client: $(CLIENT_OBJETS)
	$(GCC) $(FLAGS) $(CLIENT_OBJETS) $(LIBFT_A) $(FT_PRINTF_A) -o $(CLIENT_NAME)

clean:
	rm -rfd $(SERVER_OBJETS) $(CLIENT_OBJETS) $(BONUS_SERVER_OBJETS) $(BONUS_CLIENT_OBJETS)
	cd libft && make clean
	cd ft_printf && make clean
	@echo "\033[92mCLEAN DONE\033[0m"

fclean: clean
	rm -rfd $(SERVER_NAME) $(CLIENT_NAME)
	cd libft && make fclean
	cd ft_printf && make fclean
	@echo "\033[92mFCLEAN DONE\033[0m"

%.o: %.c minitalk.h minitalk_bonus.h
	$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

bonus: fclean libfta ft_printfa $(BONUS_SERVER_OBJETS) $(BONUS_CLIENT_OBJETS)
	$(GCC) $(FLAGS) $(BONUS_SERVER_OBJETS) $(LIBFT_A) $(FT_PRINTF_A) -o $(SERVER_NAME)
	$(GCC) $(FLAGS) $(BONUS_CLIENT_OBJETS) $(LIBFT_A) $(FT_PRINTF_A) -o $(CLIENT_NAME)
	@echo "\033[92mMinitalk bonus par Yanis Labbé\033[0m"
	@echo "\033[92mFenêtre 1: ./server\033[0m"
	@echo "\033[92mFenêtre 2: ./client pid msg\033[0m"

re: fclean all
