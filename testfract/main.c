#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

void    ft_putstr(char *s)
{
    int i;

    if (s == NULL)
        return ;
    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

int ft_atoi(const char *str)
{
    int             i;
    int             n;
    int             negtv;
    int             sum;

    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    negtv = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            negtv = -1;
        i++;
    }
    sum = 0;
    n = 0;
    while ((str[i] >= 48 && str[i] <= 57) && str[i])
    {
        n = (str[i] - 48);
        sum = ((sum * 10) + n * negtv);
        i++;
    }
    return (sum);
}

t_complex   get_complex(int x, int y, t_view *view)
{
	double      range_re;
    double      range_im;
    t_complex   number;

    range_re = (view->x_max + view->move.re) - (view->x_min + view->move.re);
    range_im = (view->y_max + view->move.im) - (view->y_min + view->move.im);
    number.re = x * (range_re / view->width) + (view->x_min + view->move.re);
    number.im = y * ( range_im / view->height) + (view->y_min + view->move.im);
    return (number);
}

double  map_to_color(int color,int old_range_max, double range_min, double range_max)
{
    double range = range_max - range_min;
    return (color * (range / old_range_max) + range_min);
}


double mapzoom(double value, double in_min, double in_max, double out_min, double out_max)
{
	return ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

//pos->interp = 1.0;
//I have a simple interpolate function to redefine the area bounding rectangle

double      interpolate(double start, double end, double interp)
{
    return (start + ((end - start) * interp));
}

/*void    zoom(t_mlx_params *data, double x, double y)
{
    t_complex center;

    data->view->zoom_factor += data->view->zoom < 1.0 ? 1 : -1;
    center.re = map_to_color(x, data->view->width, data->view->x_min, data->view->x_max);
    center.im = map_to_color(y, data->view->width, data->view->y_min, data->view->y_max);
    data->view->x_min = interpolate(center.re, data->view->x_min, data->view->zoom);
    data->view->y_min = interpolate(center.im, data->view->y_min, data->view->zoom);
    data->view->x_max = interpolate(center.re, data->view->x_max, data->view->zoom);
    data->view->y_max = interpolate(center.im, data->view->y_max, data->view->zoom);
}*/

/*int     mouse_press(int button, int x, int y, t_mlx_params *data)
{
    data->view->mouse.re = x;
    data->view->mouse.im = y;
	if (mlx->fract % 2 == 0)
    {
        if (button == 1)
            mlx->pause = mlx->pause ? 0 : 1;
    }
   	if (button == 4)
	{
		data->view->zoom = 1.5;
		zoom(data, x, y);
	}
	if (button == 5)
	{
		data->view->zoom = 1.0 / 1.5;
		zoom(data, x, y);
	}
    fill_pixel(data);
    return (1);
}*/

//To map the pixel coordinates to the center of the screen, I'm using the position function
/*void        position(int x, int y, t_mandel *man)
{
    double  *s_x;
    double  *s_y;

    s_x = &man->pos->shift_x;
    s_y = &man->pos->shift_y;
    man->c_re = (x / (WIDTH / (man->re_max - man->re_min)) + man->re_min) + *s_x;
    man->c_im =(y / (HEIGHT / (man->im_max - man->re_min)) + man->im_min) + *s_y;
    man->c_im *= 0.8;
}*/

//To zoom in, I first get the coordinates of the mouse pointer and map them to the visible area given by the rectangle defined by the (Re_Max, Re_Min, Im_Max, Im_Min) using this function, where x and y are coordinates of the pointer on a screen

/*int	mouse_move(int x, int y, t_view *view)
{
    //t_fract         *fract;
    //t_mandel        *man;

    //fract = (t_fract *)p;
    //man = fract->mandel;
    view->mouse->re = x / (view->width / (view->x_max - view->x_min)) + view->x_min;
    view->mouse->im = y / (view->height / (view->y_max - view->x_min)) + view->y_min;
    return (0);
}*/

//This function is called when a mouse wheel scroll is registered. The actual zooming is achieved by this function

int zoom_control(int key, int x, int y, t_mlx_params *data)
{
	//(void) x;
	//(void) y;
	
	data->view.mouse.re = x / (data->view.width / (data->view.x_max - data->view.x_min)) + data->view.x_min;
	data->view.mouse.im = y / (data->view.height / (data->view.y_max - data->view.y_min)) + data->view.y_min;
    double zoom_factor = 1.05;

    if (key == 5)    // zoom in
    {
        data->view.zoom /=  zoom_factor;
       apply_zoom(&data->view, 1.0 / zoom_factor);
    }
    else if (key == 4)    // zoom out
    {
        data->view.zoom *= zoom_factor;
        apply_zoom(&data->view, zoom_factor);
    }
	fill_pixel(data);
	return (0);
}
//Which calls this

void        apply_zoom(t_view *view,double zoom_factor)
{
    // Calculate the new ranges along the real and imaginary axes.
    // They are equal to the current ranges multiplied by the zoom_factor.
    double re_range = (view->x_max - view->x_min) * zoom_factor;
    double im_range = (view->y_max - view->y_min) * zoom_factor;
    double re_old_range = (view->x_max - view->x_min);
    double im_old_range = (view->y_max - view->y_min);

    // Set the new min/max values for real and imaginary axes with the center at
    // mouse coordinates m_re and m_im.
    view->x_min = view->mouse.re - (re_range * (view->mouse.re -view->x_min) / re_old_range);
    view->x_max = view->mouse.re + (re_range * (view->x_max - view->mouse.re ) / re_old_range) ;
    view->y_min = view->mouse.im - (im_range * (view->mouse.im - view->y_min) / im_old_range);
    view->y_max = view->mouse.im + (im_range * (view->y_max - view->mouse.im ) / im_old_range) ;
}

t_pixel burningship_set(int x, int y, t_view *view)
{
    t_pixel     pixel;
    t_complex   z;
    t_complex   c;
    t_complex   temp;
    double      i;

    i = 0;
	z.re = 0;
	z.im = 0;
    c = get_complex(x, y, view);
    //c = z;
    while (z.re * z.re + z.im * z.im < 256 && i < view->precision)
    {
        temp.re = fabs(z.re * z.re - z.im * z.im + c.re);
        temp.im = fabs(z.re * z.im * 2 + c.im);
        if (z.re == temp.re && z.im == temp.im)
        {
            i = view->precision;;
            break ;
        }
        z.re = temp.re;
        z.im = temp.im;
        i++;
    }
    pixel.coord = z;
    pixel.iteration = i;
    return (pixel);
}

t_pixel mandelbrot_set(int x, int y, t_view *view)
{
    t_pixel     pixel;
    t_complex   z;
    t_complex   c;
    t_complex   temp;
    double      i;

    i = 0;
    z = get_complex(x, y, view);
    c = z;
    while (z.re * z.re + z.im * z.im < 256 && i < view->precision)
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
}

t_pixel julia_set(int x, int y, t_view *view)
{
    t_pixel     pixel;
    t_complex   z;
	t_complex   c;
    t_complex   temp;
    double      i;

    i = 0;
    z = get_complex(x, y, view);
    while ((z.re * z.re + z.im * z.im < 256) && i < view->precision)
    {
        temp.re = z.re * z.re - z.im * z.im + view->mouse.re;
        temp.im = z.re * z.im * 2 + view->mouse.im;
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
}

int     ft_close(t_mlx_params *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_image(data->mlx_ptr, data->img.ptr);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(-1);
    return (0);
}

t_view	init_view(t_view *view)
{
	view->x_min = -2;
    view->y_min = -2;
    view->x_max = 2;
    view->y_max = 2;
    view->width = 600;
    view->height = 600;
	view->zoom = 1;
	view->move = (t_complex){0, 0};
	view->mouse = (t_complex){-0.835f, -0.232f};
	view->zoom_factor = 1.05;
	view->precision = 100;
	return (*view);
}

void  change_fract(t_mlx_params *data)
{
    if (data->view.fract == 3)
        data->view.fract = 1;
    else
        (data->view.fract += 1);
}

int	key_handler(int key, t_mlx_params *data)
{
	t_complex cent;

	cent = (t_complex){data->view.x_max - data->view.x_min, data->view.y_max - data->view.y_min};
	 if (key == 46)
		 change_color(data);
	 if (key == 53)
		 ft_close(data);
	 else if (key == 69)
		 *(data->prec) *= 2.0;
	 else if (key == 78)
		 *(data->prec) /= 2.0;
	 key == 123 ? data->view.move.re += cent.re / 10 : 0;
	 key == 124 ? data->view.move.re -= cent.re / 10 : 0;
	 key == 125 ? data->view.move.im -= cent.im / 10 : 0;
	 key == 126 ? data->view.move.im += cent.im / 10 : 0;
	 if (key == 45)
		 change_fract(data);
	 fill_pixel(data);
	 return (key);
}

void	change_color(t_mlx_params *data)
{
	int temp;
	temp = data->color_index.i;
	data->color_index.i = data->color_index.j;
	data->color_index.j = data->color_index.k;
	data->color_index.k = temp;
}

void	coloring_pixel(t_mlx_params *data, t_pixel *pix, t_point *point, t_view *view)
{
	int color = 0xABCDEF;
	int pixel = 0;
	
	color = map_to_color(pix->iteration, view->precision, 0, 255);
	if (pix->iteration == view->precision)
		color = 0;
	pixel = (point->y * data->img.size_line) + (point->x * 4);
	data->img.buff[pixel + data->color_index.i] = map_to_color(color * color, 255 * 255 * 255, 0, 255);
	data->img.buff[pixel + data->color_index.j] = color;
	data->img.buff[pixel + data->color_index.k] = map_to_color(sqrt(color), sqrt(255), 0, 255);
	data->img.buff[pixel + 3] = 0;
}

void	fill_pixel(t_mlx_params *data)
{
	t_complex		z;
	t_point			point;
	t_pixel			pix;
	t_view			view;

	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	view = data->view;
	data->prec = &view.precision;	
	point.y = 0;
    while (point.y < view.height)
    {
		point.x = 0;
		while (point.x < view.width)
		{
			pix = fractal(&point, &view);
			coloring_pixel(data, &pix, &point, &view); 
		   	point.x++;
		}
		point.y++;
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

void	menu()
{
	ft_putstr("For Mandelbrot_set use the key 1\n");
	ft_putstr("For julia_set use the key 2\n");
	ft_putstr("For Burningship_set use the key 3\n");
}

t_pixel	fractal(t_point *point, t_view *view)
{
	t_pixel	pix;

	if (view->fract == 1)
		(pix = mandelbrot_set(point->x, point->y, view));
	else if (view->fract == 2)
	   pix = julia_set(point->x, point->y, view);
	else if (view->fract == 3)
		pix = burningship_set(point->x, point->y, view);
	else
	{
		menu();
		exit(1);
	}
   	return (pix);
}

int ft_strcmp(const char *s1, const char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

void	init_mlx(t_mlx_params *data)
{
	data->mlx_ptr = mlx_init();
	init_view(&data->view);
	data->color_index = (t_color){1, 0, 2};
    data->win_ptr = mlx_new_window(data->mlx_ptr,  data->view.width, data->view.height, "Fractal");
    data->img.ptr = mlx_new_image(data->mlx_ptr, data->view.width, data->view.height);
    data->img.buff = mlx_get_data_addr(data->img.ptr, &(data->img.bits_per_pixel), &(data->img.size_line), &(data->img.endian));
}

int main(int argc, char **argv)
{
    t_mlx_params    data;

	if (argc != 2 || ((ft_strcmp(argv[1], "1") != 0) && (ft_strcmp(argv[1], "2") != 0) && (ft_strcmp(argv[1], "3") != 0)))
	{
		ft_putstr("Invalid arguments.\n");
		ft_putstr("Correct format: [./fractol <keycode of fractal>].\n");
		menu();
		exit (1);
	}
	init_mlx(&data);
	data.view.fract = ft_atoi(argv[1]);
	fill_pixel(&data);
	mlx_key_hook(data.win_ptr, key_handler, &data);
	mlx_mouse_hook(data.win_ptr, zoom_control, &data);
	mlx_loop(data.mlx_ptr);
}
