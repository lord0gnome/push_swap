# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guiricha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 16:55:06 by guiricha          #+#    #+#              #
#    Updated: 2016/05/01 16:18:57 by guiricha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c linked_lists.c test_funcs.c print_funcs.c \
		   linked_lists_actions.c apply_actions.c algo.c

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
	@echo "                                \n";
	@echo "                _       __  ____";
	@echo "    ____  _____(_)___  / /_/ __/";
	@echo "   / __ \/ ___/ / __ \/ __/ /_  ";
	@echo "  / /_/ / /  / / / / / /_/ __/  ";
	@echo " / .___/_/  /_/_/ /_/\__/_/     ";
	@echo "/_/                             \n";
	@echo "                      __                                 ";
	@echo "    ____  __  _______/ /_       ______      ______ _____ ";
	@echo "   / __ \/ / / / ___/ __ \     / ___/ | /| / / __ \`/ __ \\";
	@echo "  / /_/ / /_/ (__  ) / / /    (__  )| |/ |/ / /_/ / /_/ /";
	@echo " / .___/\__,_/____/_/ /_/____/____/ |__/|__/\__,_/ .___/ ";
	@echo "/_/                                             /_/      ";
	@make re -C libft && cp -f libft/libft.a ./
	@make re -C printf && cp -f printf/libftprintf.a ./
	@echo "Making final $(NAME) executable"
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
