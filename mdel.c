

void    *mandelbrot_1(void *param)
{
    t_thread    thread;
    int         n;
    t_mlx       *mlx;

    mlx = (t_mlx*)param;
    thread.p.y = -1;
    while (++thread.p.y < mlx->width / 2)
    {
        thread.p.x = -1;
        while (++thread.p.x < mlx->width / 2)
        {
            thread.c = init_complex(*mlx, thread);
            thread.z = (t_xpoint){0, 0};
            n = 0;
            while (mod(thread.z) <= mlx->r && ++n < mlx->max_iter)
            {
                mlx->fract == 5 ? complex_abs(&thread.z) : 0;
                thread.z = add(power_calc(*mlx, thread.z), thread.c);
            }
            fill_pixel(mlx, thread.p.x, thread.p.y, color(n, *mlx));
        }
    }
    return (NULL);
}

