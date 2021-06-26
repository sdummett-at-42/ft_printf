# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 06:11:54 by sdummett          #+#    #+#              #
#    Updated: 2021/06/26 09:19:20 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
AR		= ar
ARFLAGS = rcs
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= ft_printf.a
SRC		= specifiers_printing/ft_putaddr.c \
		  specifiers_printing/ft_putchar.c \
		  specifiers_printing/ft_puthex_low.c \
		  specifiers_printing/ft_puthex_up.c \
		  specifiers_printing/ft_putnbr.c \
		  specifiers_printing/ft_putstr.c

OBJ = $(SRC:.c=.o)

#INCLUDES = -I./includes

all: $(NAME)

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
