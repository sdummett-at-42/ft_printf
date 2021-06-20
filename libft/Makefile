# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 14:41:18 by sdummett          #+#    #+#              #
#    Updated: 2021/03/25 18:24:27 by sdummett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ************************************ #
#                                      #
#              VARIABLES               #
#                                      #
# ************************************ #

CC = 		gcc 
AR = 		ar
ARFLAGS = 	rcs
CFLAGS = 	-Wall -Wextra -Werror -c
NAME = 		libft.a
SRC =		ft_strlen.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_isascii.c \
			ft_strncmp.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_itoa.c \
			ft_strnstr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_isupper_bonus.c \
			ft_islower_bonus.c 
SRCBONUS =	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

# ************************************ #
#                                      #
#                RULES                 #
#                                      #
# ************************************ #

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(OBJBONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<
so:
	$(CC) -fPIC $(CFLAGS) $(SRC)
	$(CC) -shared -o libft.so $(OBJ)

clean:
	rm -f $(OBJ) $(OBJBONUS)
	rm -f libft.so

fclean: clean
	rm -f $(NAME)

re: fclean all
