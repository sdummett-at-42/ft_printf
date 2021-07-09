# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/26 06:11:54 by sdummett          #+#    #+#              #
#    Updated: 2021/07/09 14:07:32 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC		= clang
AR		= ar
ARFLAGS = rcs
CFLAGS	= -Wall -Werror -Wextra -c
NAME	= libftprintf.a
SRC		= ft_printf.c \
		  parser/format_parser.c \
		  parser/parsing_funcs.c \
		  parser/struct_init.c \
		  printers/c_printer.c \
		  printers/s_printer.c \
		  printers/p_printer.c \
		  printers/d_i_printer.c \
		  printers/u_printer.c \
		  printers/lower_x_printer.c \
		  printers/upper_x_printer.c \
		  printers/percent_printer.c \
		  printers/check_if_eq_zero.c \
		  printers/count_and_print.c \
		  printers/find_call_printer.c \
		  converters/field_width_conversion.c \
		  converters/padding_conversion.c \
		  converters/precision_conversion.c \
		  converters/x_prefix_conversion.c \
		  converters/x_prefix_padding.c \
		  utils/uitohex_low.c \
		  utils/uitohex_up.c \
		  utils/uitoa.c
OBJ		= $(SRC:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

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
