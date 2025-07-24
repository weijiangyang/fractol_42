#include "fractol.h"

int close_handler(int keysym, t_fractal *fractal)
{
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
    	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_SUCCESS);
        return (0);
}

int key_handler(int keysym, t_fractal *fractal)
{
    //printf("keysym = %d\n", keysym);

    if (keysym == XK_Escape)
        close_handler(keysym, fractal);
    else if (keysym == XK_Right)
        fractal->shift_x -= 0.5 * fractal->zoom;
    else if (keysym == XK_Left)
        fractal->shift_x += 0.5 * fractal->zoom;
    else if (keysym == XK_Up)
        fractal->shift_y -= 0.5 * fractal->zoom;
    else if (keysym == XK_Down)
        fractal->shift_y += 0.5 * fractal->zoom;
    else if (keysym == XK_equal)
        fractal->iterations_defintion += 10;
    else if (keysym == XK_minus)
        fractal->iterations_defintion -= 10;
    fractal_render(fractal);
    return (0);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
    if (button == Button5)
        fractal->zoom *= 0.95;
    else if (button == Button4 )
        fractal->zoom *= 1.06;
    fractal_render(fractal);
    return (0);
}