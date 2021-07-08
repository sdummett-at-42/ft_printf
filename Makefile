# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 06:11:54 by sdummett          #+#    #+#              #
#    Updated: 2021/07/08 22:44:44 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
AR		= ar
ARFLAGS = rcs
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= libftprintf.a

SRC		= srcs/ft_printf.c \
		  srcs/parser/format_parser.c \
		  srcs/parser/parsing_funcs.c \
		  srcs/parser/struct_init.c \
		  srcs/printers/c_printer.c \
		  srcs/printers/s_printer.c \
		  srcs/printers/p_printer.c \
		  srcs/printers/d_i_printer.c \
		  srcs/printers/u_printer.c \
		  srcs/printers/lower_x_printer.c \
		  srcs/printers/upper_x_printer.c \
		  srcs/printers/percent_printer.c \
		  srcs/printers/check_if_eq_zero.c \
		  srcs/printers/count_and_print.c \
		  srcs/printers/find_call_printer.c \
		  srcs/converters/field_width_conversion.c \
		  srcs/converters/padding_conversion.c \
		  srcs/converters/precision_conversion.c \
		  srcs/converters/x_prefix_conversion.c \
		  srcs/converters/x_prefix_pad_conversion.c \
		  srcs/utils/uitohex_low.c \
		  srcs/utils/uitohex_up.c \
		  srcs/utils/uitoa.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

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
