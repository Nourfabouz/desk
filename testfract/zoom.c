#include "fractol.h"

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

void        apply_zoom(t_view *view,double zoom_factor)
{
	double re_range = (view->x_max - view->x_min) * zoom_factor;
    double im_range = (view->y_max - view->y_min) * zoom_factor;
    double re_old_range = (view->x_max - view->x_min);
    double im_old_range = (view->y_max - view->y_min);
	
	view->x_min = view->mouse.re - (re_range * (view->mouse.re -view->x_min) / re_old_range);
    view->x_max = view->mouse.re + (re_range * (view->x_max - view->mouse.re ) / re_old_range) ;
    view->y_min = view->mouse.im - (im_range * (view->mouse.im - view->y_min) / im_old_range);
    view->y_max = view->mouse.im + (im_range * (view->y_max - view->mouse.im ) / im_old_range) ;
}
