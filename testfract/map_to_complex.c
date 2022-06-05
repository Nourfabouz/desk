#include "fractol.h"

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

