# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/19 14:11:58 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2019/03/20 08:41:03 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = minishell

SRC = minishell.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/

HEADER = minishell.h

LIBFT.A = ./libft/libft.a

all: libs $(NAME)

$(NAME): $(SRC) $(LIBFT.A) $(HEADER)
		@$(CC) -o $(NAME) $(FLAGS) $(SRC) -I./includes $(LIBFT.A)
		@echo "\033[1;32mMINISHELL								OK\033[0m"

libs:
		@(cd $(LIBFT) && $(MAKE))

clean:
		@rm -f $(OBJ)
		@rm -f *.gch
		@rm -rf *.dSYM
		@rm -f .DS_Store
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mCLEAN MINISHELL								OK\033[0m"

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mFCLEAN MINISHELL							OK\033[0m"

re: fclean all

.PHONY : all clean fclean re