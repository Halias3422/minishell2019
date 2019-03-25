# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/19 14:11:58 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2019/03/25 15:19:46 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = minishell

SRC = minishell_srcs/main.c \
	  minishell_srcs/minishell.c \
	  minishell_srcs/util_tools.c \
	  minishell_srcs/builtins.c \
	  minishell_srcs/modif_env_data.c \
	  minishell_srcs/echo_builtin.c \
	  minishell_srcs/cd_builtin.c \
	  minishell_srcs/setenv_builtin.c \
	  minishell_srcs/unsetenv_builtin.c \
	  minishell_srcs/handle_dollar_tilde.c \
	  minishell_srcs/handle_tilde.c \
	  minishell_srcs/get_pwd_old_pwd.c \
	  minishell_srcs/free.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

LIBFT = ./libft/

HEADER = minishell.h

LIBFT.A = ./libft/libft.a

all: libs $(NAME)

$(NAME): $(SRC) $(LIBFT.A) $(HEADER)
		@$(CC) -o $(NAME) $(FLAGS) $(SRC) -I. $(LIBFT.A)
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
