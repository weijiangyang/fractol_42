/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:30:40 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/22 10:30:42 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    my_pixels_put(int x, int y, t_img  *img, int color)
{
    int offset;

    offset = (y * img->line_len) + (x * (img->bpp / 8));
    *((unsigned int *)(img->pixels_ptr + offset) )= color;
}
void    handle_pixels(int x, int y, t_fractol *fractol)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = 0;
    z.y = 0;
    c.x = map(x, -2, 2, 0, WIDTH);
    c.y = map(y, +2, -2, 0, HEIGHT);
    while (i < fractol->iterations_definition)
    {
        z = sum_complex(square_complex(z), c);
        if (z.x * z.x + z.y * z.y > fractol->escaped_value)
        {
            color = map(i, BLACK, WHITE, 0, fractol->iterations_definition);
            my_pixels_put(x, y, &fractol->img, color);
            return ;
        }
        my_pixels_put(x, y, &fractol->img, PSYCHEDELIC_PURPLE);
        i++;
    }
}

void    fractol_render(t_fractol *fractol)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handle_pixels(x, y, fractol);
        }
        mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img_ptr, x, y);
        
    }

}

