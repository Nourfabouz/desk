#ifndef FRACTOL_H
# define FRACTOL_H

/*# include "libft.h"*/
# include "mlx.h"
# include <math.h>
#include <stdlib.h>

typedef struct s_color
{
	int i;
	int j;
	int k;
}				t_color;
typedef struct s_complex
{
    double  re;
    double  im;
}               t_complex;

typedef struct s_pixel
{
    t_complex   coord;
    int         iteration;
}				t_pixel;

typedef struct  s_img
{
    void	*ptr;
    char	*buff;
    int		bits_per_pixel;
    int		endian;
    int		size_line;
}				t_img;

typedef struct s_view
{
    double      x_max;
    double      x_min;
    double      y_max;
    double      y_min;
    int         width;
    int         height;
	int			fract;
    double      zoom;
	double		zoom_factor;
    int         precision;
    t_complex   mouse;
    t_pixel     pix;
    int         color;
	t_complex	move;
}               t_view;

typedef struct mlx_params
{
    void    *mlx_ptr;
    void    *win_ptr;
	char	*add;
	t_img	img;
	t_color	color_index;
	int		*prec;
	t_view	view;
}				t_mlx_params;

typedef struct s_point
{	
	int	x;
	int y;
}				t_point;

t_complex   get_complex(int x, int y, t_view *view);
void		change_fract(t_mlx_params *data);
t_pixel		fractal(t_point *point, t_view *view);
t_pixel 	mandelbrot_set(int x, int y, t_view *view);
t_pixel 	burningship_set(int x, int y, t_view *view);
t_pixel 	julia_set(int x, int y, t_view *view);
void    	coloring_pixel(t_mlx_params *data, t_pixel *pix, t_point *point, t_view *view);
void    	fill_pixel(t_mlx_params *data);
void    	change_color(t_mlx_params *data);
int			zoom_control(int key, int x, int y, t_mlx_params *data);
void		apply_zoom(t_view *view,double zoom_factor);
int			mouse_move(int x, int y, t_view *view);
int 		mouse_hook(int mousecode, int x, int y, t_mlx_params *data);

#endif
