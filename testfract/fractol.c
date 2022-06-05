#include "fractol.h"

void    menu()
{
    ft_putstr("For Mandelbrot_set use the key 1\n");
    ft_putstr("For julia_set use the key 2\n");
    ft_putstr("For Burningship_set use the key 3\n");
}

t_pixel fractal(t_point *point, t_view *view)
{
    t_pixel pix;

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
