# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 10:42:31 by souaouri          #+#    #+#              #
#    Updated: 2023/12/12 10:42:31 by souaouri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src_o = ft_printf.o print_character.o print_digit.o print_format.o print_hex_lower.o print_hex_upper.o \
		print_string.o print_unsigned_int.o 

NAME = libftprintf.a
CFLAGS = -Wextra -Werror -Wall
HEADER = ft_printf.h

all : $(NAME)

$(NAME) : $(src_o)
	ar rc  $(NAME) $(src_o) $<

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $<

clean :
	rm -rf $(src_o)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY :  clean
