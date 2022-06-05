#include "fractol.h"

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
