#include "fractol.h"

void    fill_pixel(t_fpoint c, t_view view, char **buff)
{
    int x;
    int y;

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
                /*pixel = (y * size_line) + (x * 4);
                buff[pixel + 0] = (bright)  & 0xFF;
                buff[pixel + 1] = (bright >> 8) & (0xFF);
                buff[pixel + 2] = (bright >> 16) & (0xFF);
                buff[pixel + 3] = (bright >> 24);*/
                color = 0;
            }
            pixel = (y * size_line) + (x * 4);
           *(buff[pixel + 1]) = mapToReal(color * color, 255 * 255 * 255 * (1 - n / 100), 0, 255);
           *(buff[pixel + 0]) = color;//(color >> 8) /*& (0xFF)*/;
            *(buff[pixel + 2]) = mapToReal(sqrt(color), sqrt(255), 0, 255);//(color >> 16) /*& (0xFF)*/;
            *(buff[pixel + 3]) = 0;
            x++;
        }
        y++;
    }
}
