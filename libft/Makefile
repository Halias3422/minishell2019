# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/29 10:52:01 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2019/02/11 14:38:53 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

PROJECT_NAME = libft
NAME    = libft.a
#EXE = $(PROJECT_NAME)

LIBFT_SRC = libft/add_conversion.c libft/add_flag2.c libft/add_flags.c libft/bonus_conversion_type_1.c libft/bonus_conversion_type_2.c libft/bonus_conversion_type_3.c libft/check_num_length.c libft/conversion_type.c libft/conversion_type2.c libft/determ_data.c libft/ft_atoi.c libft/ft_bzero.c libft/ft_copy_part_str.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isblank.c libft/ft_isdigit.c libft/ft_islower.c libft/ft_isprint.c libft/ft_isupper.c libft/ft_itoa.c libft/ft_itoa_base_uns.c libft/ft_list_last.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_printf.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putnstrn.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_range.c libft/ft_strcapitalizer.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strndup.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strrev.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_swap_let_string.c libft/ft_tolower.c libft/ft_toupper.c libft/get_next_line.c libft/handle_flags_order.c libft/handle_float.c libft/handle_prec_and_width.c libft/others.c libft/others2.c libft/print_colors.c libft/print_printf.c libft/check_content_equal.c libft/free_both_strjoin.c

#CURR_SRC = list_rep.c

LIBFT_OBJ  = $(LIBFT_SRC:.c=.o)
#CURR_OBJ = $(CURR_SRC:.c=.o)

CC = @gcc

MAIN = list_rep.c

FLAGS = -Wall -Werror -Wextra

CFLAGS = $(FLAGS) -I./includes -c

OBJ_DIR = objects/

HEADERS = includes/libft.h \
		  includes/ft_printf.h \
		  includes/get_next_line.h

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(HEADERS) #$(CURR_OBJ)
	@ar rcs $(NAME) $(LIBFT_OBJ) #$(CURR_OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32mLIBFT									OK\033[0m"

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) $^

exe : $(NAME)
	@gcc -o $(EXE) -I./includes $(MAIN) $(NAME)

clean:
	@rm -rf $(LIBFT_OBJ)
	@rm -rf $(CURR_OBJ)
	@rm -rf *.gch
	@rm -rf *.dSYM
	@rm -f .DS_Store
	@echo "\033[1;31mCLEAN LIBFT								OK\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(EXE)
	@echo "\033[1;31mFCLEAN LIBFT								OK\033[0m"

re: fclean all

.PHONY : all clean fclean re
