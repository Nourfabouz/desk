

#include "fractol.h"

/*
** This function iterates the image, pixel by pixel, using the y * WIDTH + x
** equation and gives and then according to each pixel iteration -
** pixel->iterations, it gives a color to the pixel, which is then put in the
** image using the my_mlx_pixel_put() function.
** At the end of the function the image is uploaded to the window -
** mlx_put_image_to_window()
**
** @param	t_ctrl	*control - main struct of the program that stores all
** 							important variables.
*/
void	pixels_to_image(t_ctrl *control)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < control->width)
	{
		y = 0;
		while (y < control->height)
		{
			color = get_color((control->pixels + y * WIDTH + x)->iteration,
				control->view.precision, control->view.color);
			my_mlx_pixel_put(control->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(control->data->mlx, control->data->win,
		control->img->img, 0, 0);
}

/*
** This function iterates the image, pixel by pixel using the y * WIDTH + x
** equation and calls the fn_fractal function to get the t_pixel struct from
** each pixel in the image.
**
** @param	t_ctrl	*control - main struct of the program that stores all
** 							important variables.
*/
void	fractal_render(t_ctrl *control)
{
	int	x;
	int	y;

	x = 0;
	while (x < control->width)
	{
		y = 0;
		while (y < control->height)
		{
			*(control->pixels + y * WIDTH + x)
						= control->fractal->fn_fractal(x, y, &control->view);
			y++;
		}
		x++;
	}
	pixels_to_image(control);
}
