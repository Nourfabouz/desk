NAME= fractol
LIB= libft/libft.a
FLAGS= -Wall -Wextra -Werror
OBJ= srcs/complex_calc.o srcs/init_fractal.o srcs/keyboard.o\
     srcs/mandelbrot.o srcs/init.o srcs/julia.o\
     srcs/mouse.o srcs/main.o srcs/color.o srcs/image.o srcs/complex_power.o\
     srcs/tricorn.o srcs/julia_bar_set.o srcs/zoom.o
INC= includes/

all : $(LIB) $(NAME)

%.o : %.c $(INC)
    clang $(FLAGS) -c -o $@ $< -I $(INC)
$(NAME) : $(OBJ)
    @clang -o $@ $^ -lmlx -framework OpenGL -framework AppKit\
        -I $(INC) libft/libft.a

$(LIB) :
	@make -C libft/

clean :
	@rm -rf $(OBJ) && make -C libft/ clean
   
