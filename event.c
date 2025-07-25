/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:55:38 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/25 11:18:18 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_equal)
		fractal->iterations_defintion += 10;
	else if (keysym == XK_minus)
		fractal->iterations_defintion -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	prev_zoom;
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;

	prev_zoom = fractal->zoom;
	if (button == Button4)
		zoom_factor = 1.05;
	else if (button == Button5)
		zoom_factor = 0.95;
	else
		return (0);
	fractal->zoom *= zoom_factor;
	mouse_x = map(x, fractal->scale_x);
	mouse_y = map(y, fractal->scale_y);
	fractal->shift_x += (mouse_x * (prev_zoom - fractal->zoom));
	fractal->shift_y += (mouse_y * (prev_zoom - fractal->zoom));
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, fractal->scale_x) * fractal->zoom
			+ fractal->shift_x;
		fractal->julia_y = map(y, fractal->scale_y) * fractal->zoom
			+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
