# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 18:49:34 by fabou-za          #+#    #+#              #
#    Updated: 2021/12/09 18:49:52 by fabou-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# define the C compiler to use
CC = gcc
#define compiler flags
CFLAGS = -Wall -Wextra -Werror
#define the object files that this project needs
OBJFILES =\
		  ft_atoi.o \
		  ft_bzero.o \
		  ft_calloc.o \
		  ft_isalnum.o \
		  ft_isalpha.o \
		  ft_isascii.o \
		  ft_isdigit.o \
		  ft_isprint.o \
		  ft_memchr.o \
		  ft_memcmp.o \
		  ft_memcpy.o \
		  ft_memmove.o \
		  ft_memset.o \
		  ft_strchr.o \
		  ft_strdup.o \
		  ft_strlcat.o \
		  ft_strlcpy.o \
		  ft_strlen.o \
		  ft_strncmp.o \
		  ft_strnstr.o \
		  ft_strrchr.o \
		  ft_tolower.o \
		  ft_substr.o \
		  ft_strjoin.o \
		  ft_strtrim.o \
		  ft_toupper.o \
		  ft_split.o \
		  ft_itoa.o \
		  ft_strmapi.o \
		  ft_striteri.o \
		  ft_putchar_fd.o \
		  ft_putstr_fd.o \
		  ft_putendl_fd.o \
		  ft_putnbr_fd.o

BONUSOBJ =\
		  ft_lstsize.o \
		  ft_lstadd_back.o \
		  ft_lstlast.o \
		  ft_lstadd_front.o \
		  ft_lstnew.o \
		  ft_lstdelone.o \
		  ft_lstclear.o \
		  ft_lstiter.o \
		  ft_lstmap.o
#define the name of the library
NAME = libft.a
INC = libft.h

all : $(NAME)

$(NAME): $(OBJFILES)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<
	ar -rcs $(NAME) $@

clean:
	rm -f $(OBJFILES) $(BONUSOBJ)

fclean: clean
	rm -f $(NAME)

bonus : $(OBJFILES) $(BONUSOBJ)

re: fclean all
