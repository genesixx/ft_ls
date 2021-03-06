# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 12:59:48 by elebouch          #+#    #+#              #
#    Updated: 2018/02/05 09:42:52 by elebouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INCLUDE = -I libft/includes/ -I includes/

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE) 

SRC= \
	main.c \
	display.c \
	display_long.c\
	display_miscs.c \
	processing.c \
	sort.c \
	free.c \
	utils.c \
	tfile_utils.c\
	putpad.c \
	reverse.c \
	sortarr.c \
	freearr.c \
	error.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all:  lib

$(NAME):  $(OBJ)
	@echo  "\033[94mCompiling ft_ls\033[0m"
	@$(CC) $(CFLAGS) $^ -o $(NAME) -L libft/ -lftprintf
	@echo  "\033[34mDone\033[0m"

lib:
	@echo "\033[94mCompiling libft and printf\033[0m"
	@$(MAKE) -C libft/
	@$(MAKE) $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean 
	@$(MAKE) all
.PHONY: clean lib fclean re all
