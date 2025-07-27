/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:59:19 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/27 11:33:06 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel_1(int x, int y, int i, t_fractal *fractal)
{
	int		color;
	t_scale	scale_color;

	scale_color.new_min = BLACK;
	scale_color.new_max = WHITE;
	scale_color.old_min = 0;
	scale_color.old_max = fractal->iterations_defintion;
	color = map(i, scale_color);
	my_pixel_put(x, y, &fractal->img, color);
	return ;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.x = (map(x, fractal->scale_x) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, fractal->scale_y) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_defintion)
	{
		if (!ft_strncmp(fractal->name, "burning_ship", 12))
		{
			z.x = fabs(z.x);
			z.y = fabs(z.y);
		}
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			handle_pixel_1(x, y, i, fractal);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, WHITE);
}

int	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
	return (0);
}
