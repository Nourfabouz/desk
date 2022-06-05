#include "mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

typedef struct params 
{
	void 	*mlx_ptr;
   	void 	*win_ptr;
	int		x;
	int		y;
} t_params;

typedef struct  s_fpoint
{
    double r;
    double i;
}               t_fpoint;

typedef struct view
{
    double x_min;
    double x_max;
    double y_min;
	double y_max;
} t_view;

typedef struct  s_img
{
    void    *ptr;
    char     *buff;
    int     bits_per_pixel;
    int     endian;
    int     size_line;
}               t_img;

double	mapToReal(int x, int width, double x_min, double x_max)
{
	double range = x_max - x_min;
	return (x * (range / width) + x_min);
}

double  mapToImaginary(int y, int height, double y_min, double y_max)
{
	double range = y_max - y_min;
	return (y * (range / height ) + y_min);
}

long double map(long double value, long double in_min, long double in_max, long double out_min, long double out_max)
{
	return ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
}
int findMandelbrot(t_fpoint c, int max_iterations)
{
	int it = 0;
	t_fpoint z;
	z.r = 0.0;
	z.i = 0.0;

	while (it < max_iterations && z.r * z.r + z.i * z.i < 4.0)
	{
		double temp = z.r * z.r - z.i * z.i + c.r;
		z.i = (2.0 *z.r *z.i + c.i);
		z.r = (temp);
		it++;
	}
	return (it);
}

/*t_pixel mandelbrot_set(int x, int y, t_view *view)
{
    t_pixel     pixel;
    t_complex   z;
    t_complex   c;
    t_complex   temp;
    double      i;

    i = 0;
    z = get_complex(x, y, view);
    c = z;
    while (z.re * z.re + z.im * z.im <  && i < iterations)
    {
        temp.re = z.re * z.re - z.im * z.im + c.re;
        temp.im = z.re * z.im * 2 + c.im;
        if (z.re == temp.re && z.im == temp.im)
        {
            i = view->precision;
            break ;
        }
        z.re = temp.re;
        z.im = temp.im;
        i++;
    }
    pixel.coord = z;
    pixel.iteration = i;
    return (pixel);
}*/

int	close_win	(int keycode, t_params *data) 
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}
/*void	fill_pixel(t_fpoint c, t_view view, t_img *img)
{
	int x;
	int y;
	int color;
	int pixel;
	int height;
	int width;
	int n;
	color = 0xABCDEF;
    width = 600;
    height = 600;
	view = (t_view){-2, 2, -2, 2};
    y = 0;
    while (y <= height)
    {
        x = 0;
        while (x <= width)
        {
            c.r = mapToReal(x, width, view.x_min, view.x_max);
            c.i = mapToImaginary(y, height, view.y_min, view.y_max);

            int n = findMandelbrot(c, 100);
            //pixel = (y * size_line) + (x * 4);
            //mlx_pixel_put(data->mlx_ptr, data->win_ptr, y, x++, color);
            color = mapToReal(n, 100, 0, 255);
            if ( n == 100)
            {
                pixel = (y * size_line) + (x * 4);
                buff[pixel + 0] = (bright)  & 0xFF;
                buff[pixel + 1] = (bright >> 8) & (0xFF);
                buff[pixel + 2] = (bright >> 16) & (0xFF);
                buff[pixel + 3] = (bright >> 24);
                color = 0;
            }
            pixel = (y * img->size_line) + (x * 4);
           	img->buff[pixel + 1] = mapToReal(color * color, 255 * 255 * 255 * (1 - n / 100), 0, 255);
           	img->buff[pixel + 0] = color;(color >> 8) & (0xFF);
            img->buff[pixel + 2] = mapToReal(sqrt(color), sqrt(255), 0, 255);(color >> 16) & (0xFF);
            img->buff[pixel + 3] = 0;
            x++;
        }
        y++;
    }
}*/

int key_handler(int key, t_params *data, t_fpoint c, t_img *img)
{
	float		x;
	float		y;
	int			pixel;
	int 		color;
	int			n;
	int			width;
	int			height;
	t_view		view;

	view = (t_view){-2, 2, -2, 2};
	width = 600;
	height = 600;
	color = 0xABCDEF;
	ft_putchar('F');
	img.ptr = mlx_new_image(data->mlx_ptr, width, height);
	img.buff = mlx_get_data_addr(img.ptr, &(img.bits_per_pixel), &(img.size_line), &(img.endian));
	//fill_pixel(c, view, img);
	y = 0;
    while (y <= height)
    {
        x = 0;
        while (x <= width)
        {
            c.r = mapToReal(x, width, view.x_min, view.x_max);
            c.i = mapToImaginary(y, height, view.y_min, view.y_max);

            int n = findMandelbrot(c, 100);
            //pixel = (y * size_line) + (x * 4);
            //mlx_pixel_put(data->mlx_ptr, data->win_ptr, y, x++, color);
            color = mapToReal(n, 100, 0, 255);
            if ( n == 100)
				color = 0;
            pixel = (y * img->size_line) + (x * 4);
            img->buff[pixel + 1] = mapToReal(color * color, 255 * 255 * 255 * (1 - n / 100), 0, 255);
            img->buff[pixel + 0] = color;//(color >> 8) /*& (0xFF)*/;
            img->buff[pixel + 2] = mapToReal(sqrt(color), sqrt(255), 0, 255);//(color >> 16) /*& (0xFF)*/;
            img->buff[pixel + 3] = 0;
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.ptr, 0, 0);
	return (0);
}

void	key_handler(int key,t_params *data)
{
    float       x;
    float       y;
    int         pixel;
    int         color;
    int         n;
    int         width;
    int         height;
    t_view      view;
	t_fpoint 	c;
	t_img       img;

    width = 600;
    height = 600;
    img.ptr = mlx_new_image(data->mlx_ptr, width, height);
    img.buff = mlx_get_data_addr(img.ptr, &(img.bits_per_pixel), &(img.size_line), &(img.endian));
    fill_pixel(c, view, &img);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img.ptr, 0, 0);
}

int main(){
	t_params 	data;
	t_fpoint 	f;

	data.mlx_ptr = mlx_init();
	data.x = 600;
	data.y = 600;
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.x, data.y, "Mandelbrot");
	//key_handler(&data);
	mlx_hook(data.win_ptr, 2, 0, key_handler, &data);
	/*mlx_hook(data.win_ptr, 2, 0, close_win, &data);*/
	mlx_loop(data.mlx_ptr);
}
