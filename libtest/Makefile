# define the C compiler to use
CC = gcc
#define compiler flags
CFLAGS = -Wall -Wextra -Werror
#define the object files that this project needs
OBJFILES = ft_atoi.o \
ft_bzero.o\
ft_calloc.o\
ft_isalnum.o\
ft_isalpha.o\
ft_isascii.o\
ft_isdigit.o\
ft_isprint.o\
ft_memchr.o\
ft_memcmp.o\
ft_memcpy.o\
ft_memmove.o\
ft_memset.o\
ft_strchr.o\
ft_strdup.o\
ft_strlcat.o\
ft_strlcpy.o\
ft_strlen.o\
ft_strncmp.o\
ft_strnstr.o\
ft_strrchr.o\
ft_tolower.o\
ft_substr.o\
ft_strjoin.o\
ft_strtrim.o\
ft_toupper.o\
ft_split.o\
ft_putnbr_fd.o\
ft_putchar_fd.o\
ft_putendl_fd.o\
ft_putstr_fd.o
#define the name of the executable file
NAME = libft.a 

all : $(NAME)

$(NAME): $(OBJFILES)
	ar rcs $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

so:
	gcc -nostartfiles -shared -o libft.so $(OBJFILES)

re: fclean all
