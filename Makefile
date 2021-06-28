# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 06:11:54 by sdummett          #+#    #+#              #
#    Updated: 2021/06/28 04:44:28 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
AR		= ar
ARFLAGS = rcs
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= ft_printf.a
SRC		= specifiers_printing/pointer_handler.c \
		  specifiers_printing/char_handler.c \
		  specifiers_printing/hexadecimal_handler.c \
		  specifiers_printing/numbers_handler.c \
		  specifiers_printing/string_handler.c \
		  specifiers_printing/ft_putpercent.c \
		  specifier_handler.c \
		  ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

#
#---->Add colors
#

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a ft_printf.a
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
