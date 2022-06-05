
#include "fractol.h"

int	mouse_hook(int mousecode, int x, int y, t_ctrl *control)
{
	(void) x;
	(void) y;
	if (mousecode == ZOOM_IN)
		control->view.zoom *= 1.05;
	else if (mousecode == ZOOM_OUT)
		control->view.zoom /= 1.05;
	fractal_render(control);// fill_pixel and put images.
	return (mousecode);
}
