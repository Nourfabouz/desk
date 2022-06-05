#include "fractol.h"

double  map_to_color(int color,int old_range_max, double range_min, double range_max)
{
    double range = range_max - range_min;
    return (x * (range / old_range_max) + range_min);
}
