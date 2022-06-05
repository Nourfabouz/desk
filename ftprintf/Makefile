# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 15:36:44 by fabou-za          #+#    #+#              #
#    Updated: 2022/02/27 15:10:28 by fabou-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wextra -Werror -Wall

OBJ = ft_printf.o\
	  ft_putnbr.o\
	  hexadecimal.o\
	  ft_putnbrunsigned.o\
	  pointer.o\
	  ft_putchar.o\
	  ft_putstr_fd.o\
	  ft_strlen.o

#define the name of the executable file
NAME = libftprintf.a
INC = ft_printf.h

all : $(NAME)

$(NAME): $(OBJ)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<
	ar -rcs $(NAME) $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all	
