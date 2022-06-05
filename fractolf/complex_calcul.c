#include "fractol.h"

double  map_to_real(int x, int width, double min_r, double max_r)
{
    double range = max_r - min_r;
    return (x * (range / width) + min_r);
}

double  map_to_imaginary(int y, int height, double min_i, double max_i)
{
    double range = max_i - min_i;
    return (y * (range / height ) + min_i);
}


