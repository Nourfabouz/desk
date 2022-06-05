#include "mlx.h"
#include <math.h>
#include "../libft/libft.h"

typedef struct  s_fpoint
{
    double rl;
    double im;
}               t_fpoint;

typedef struct  s_view
{
    double  r_min;
    double  i_min;
    double  r_max;
    double  i_max;
}               t_view;

typedef struct  s_img
{
    void    *ptr;
    int     *str;
    int     bpp;
    int     endian;
    int     sl;
}               t_img;

typedef struct  s_mlx
{
    t_xpoint    c;
    t_img       img;
    t_mouse     mouse;
    t_xpoint    move;
    t_color     color;
    double      zoom;
    double      zoom_factor;
    t_center    center;
    double      r;
    void        *init;
    void        *win;
    int         fract;
    int         width;
    int         height;
    int         max_iter;
    int         pause;
    int         pow;
}               t_mlx;

double  map_to_real(int x, int width, double min_r, double max_r);
double  map_to_imaginary(int y, int height, double min_i, double max_i);
int findMandelbrot(t_fpoint c, int max_iterations);
void    fill_pixel(t_fpoint c, t_view view, char **buff);
