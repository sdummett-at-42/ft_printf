# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 06:11:54 by sdummett          #+#    #+#              #
#    Updated: 2021/07/05 18:31:14 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
AR		= ar
ARFLAGS = rcs
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= libftprintf.a

SRC		= specifiers/c_specifier/char_handler.c \
		  specifiers/s_specifier/string_handler.c \
		  specifiers/p_specifier/pointer_handler.c \
		  specifiers/d_i_specifier/integer_handler.c \
		  specifiers/u_specifier/u_integer_handler.c \
		  specifiers/x_lower_specifier/hexalow_handler.c \
		  specifiers/x_upper_specifier/hexaup_handler.c \
		  specifiers/percent_specifier/percent_handler.c \
		  utils/specifier_handler.c \
		  utils/ft_putchar.c \
		  utils/ft_putstr.c \
		  utils/uitoa.c \
		  utils/ptf_struct_initializer.c \
		  ft_printf.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

#
#---->Add colors
#

$(NAME): $(OBJ)
	make -C libft
	mv libft/libft.a libftprintf.a
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
