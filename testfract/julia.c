#include "fractol.h"

t_pixel julia_set(int x, int y, t_view *view)
{
    t_pixel     pixel;
    t_complex   z;
    t_complex   temp;
    double      i;

    i = 0;
    z = get_complex(x, y, view);
    while ((z.re * z.re + z.im * z.im < 4) && i < view->precision)
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
