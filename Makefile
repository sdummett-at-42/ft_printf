# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 06:11:54 by sdummett          #+#    #+#              #
#    Updated: 2021/07/08 18:48:17 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
AR		= ar
ARFLAGS = rcs
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= libftprintf.a

SRC		= srcs/c_specifier.c \
		  srcs/s_specifier.c \
		  srcs/p_specifier.c \
		  srcs/d_i_specifier.c \
		  srcs/u_specifier.c \
		  srcs/lower_x_specifier.c \
		  srcs/upper_x_specifier.c \
		  srcs/percent_specifier.c \
		  srcs/format_parser.c \
		  srcs/find_call_printer.c \
		  srcs/uitoa.c \
		  srcs/struct_init.c \
		  srcs/count_and_display.c \
		  srcs/uitohex_low.c \
		  srcs/uitohex_up.c \
		  srcs/check_if_eq_zero.c \
		  srcs/precision_handler.c \
		  srcs/width_handler.c \
		  srcs/padding_handler.c \
		  srcs/prefix_handler.c \
		  srcs/parsing_funcs.c \
		  srcs/sharp_padding.c \
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

bonus: all

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
