#include "fractol.h"

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
