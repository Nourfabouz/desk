/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:15:37 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/05/25 15:21:55 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This function initiates struct s_control (t_ctrl). It creates a window, and
** an image using the ft_malloc() function and initiates a connection with mlx.
** It also allocates the necessary space for pixels - the number of pixels.
**
** @param	char	*name	- name of the window.
**
** @returns
** 	The init_control() function returns a pointer to the struct t_ctrl, already
** 	initiated, if successful. In case of error the error_message() function is
** 	called and the program exits with EXIT_FAILURE.
*/
t_ctrl	*init_control(char *name)
{
	t_ctrl	*control;
	t_data	*data;
	t_img	*img;
	t_pixel	*pixels;

	control = (t_ctrl *) malloc(sizeof(t_ctrl));
	pixels = (t_pixel *) malloc(sizeof(t_pixel) * (WIDTH * HEIGHT));
	control->pixels = pixels;
	data = (t_data *) malloc(sizeof(t_data));
	data->mlx = mlx_init();
	if (!data->mlx)
		error_message(MLX_ERROR);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, name);
	//img = (t_img *) malloc(sizeof(t_img), error_message);
	img = (t_img *) malloc(sizeof(t_img));
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
		&img->line_len, &img->endian);
	control->img = img;
	control->data = data;
	return (control);
}
