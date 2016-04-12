# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/04/12 16:23:57 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c
NAME = push_swap
CC = gcc
CFLAGS = -Werror -Wextra -Wall
OBJ_NAME = $(SRC_NAME:.c=.o)
	FRAMEWORKS = -framework OpenGL -framework AppKit
	STCS = libftprintf.a libft.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ_NAME)
	@rm -f libft.a
	@echo "Making";
	@echo "    __    ________  ____________";
	@echo "   / /   /  _/ __ )/ ____/_  __/";
	@echo "  / /    / // __  / /_    / /   ";
	@echo " / /____/ // /_/ / __/   / /    ";
	@echo "/_____/___/_____/_/     /_/     ";
	@make re -C libft && cp -f libft/libft.a ./
	@make re -C printf && cp -f printf/libftprintf.a ./
	@echo "                                \n\nMaking";
	@echo "          _____                    _____                    _____                    _____                _____                    _____          ";
	@echo "         /\    \                  /\    \                  /\    \                  /\    \              /\    \                  /\    \         ";
	@echo "        /::\    \                /::\    \                /::\    \                /::\____\            /::\    \                /::\    \        ";
	@echo "       /::::\    \              /::::\    \               \:::\    \              /::::|   |            \:::\    \              /::::\    \       ";
	@echo "      /::::::\    \            /::::::\    \               \:::\    \            /:::::|   |             \:::\    \            /::::::\    \      ";
	@echo "     /:::/\:::\    \          /:::/\:::\    \               \:::\    \          /::::::|   |              \:::\    \          /:::/\:::\    \     ";
	@echo "    /:::/__\:::\    \        /:::/__\:::\    \               \:::\    \        /:::/|::|   |               \:::\    \        /:::/__\:::\    \    ";
	@echo "   /::::\   \:::\    \      /::::\   \:::\    \              /::::\    \      /:::/ |::|   |               /::::\    \      /::::\   \:::\    \   ";
	@echo "  /::::::\   \:::\    \    /::::::\   \:::\    \    ____    /::::::\    \    /:::/  |::|   | _____        /::::::\    \    /::::::\   \:::\    \  ";
	@echo " /:::/\:::\   \:::\____\  /:::/\:::\   \:::\____\  /\   \  /:::/\:::\    \  /:::/   |::|   |/\    \      /:::/\:::\    \  /:::/\:::\   \:::\    \ ";
	@echo "/:::/  \:::\   \:::|    |/:::/  \:::\   \:::|    |/::\   \/:::/  \:::\____\/:: /    |::|   /::\____\    /:::/  \:::\____\/:::/  \:::\   \:::\____\\";
	@echo "\::/    \:::\  /:::|____|\::/   |::::\  /:::|____|\:::\  /:::/    \::/    /\::/    /|::|  /:::/    /   /:::/    \::/    /\::/    \:::\   \::/    /";
	@echo " \/_____/\:::\/:::/    /  \/____|:::::\/:::/    /  \:::\/:::/    / \/____/  \/____/ |::| /:::/    /   /:::/    / \/____/  \/____/ \:::\   \/____/ ";
	@echo "          \::::::/    /         |:::::::::/    /    \::::::/    /                   |::|/:::/    /   /:::/    /                    \:::\    \     ";
	@echo "           \::::/    /          |::|\::::/    /      \::::/____/                    |::::::/    /   /:::/    /                      \:::\____\    ";
	@echo "            \::/____/           |::| \::/____/        \:::\    \                    |:::::/    /    \::/    /                        \::/    /    ";
	@echo "                                |::|   |               \:::\    \                   |::::/    /      \/____/                          \/____/     ";
	@echo "                                |::|   |                \:::\    \                  /:::/    /                                                    ";
	@echo "                                \::|   |                 \:::\____\                /:::/    /                                                     ";
	@echo "                                 \:|   |                  \::/    /                \::/    /                                                      ";
	@echo "                                  \|___|                   \/____/                  \/____/                                                       ";
	@echo "                                                                                                                                                  ";
	@$(CC) -o $(NAME) $(OBJ_NAME) $(STCS) $(FRAMEWORKS)

$(OBJ_NAME):
	@$(CC) $(CFLAGS) -c $(SRC_NAME)
clean:
	@rm -f *.o
	@rm -f *.a
	@make fclean -C libft
	@make clean -C printf

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
