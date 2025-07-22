/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 09:49:26 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/22 09:49:31 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void  data_init(t_fractol *fractol)
{
    fractol->escaped_value = 4;
    fractol->iterations_definition = 42;
}

static void    malloc_error()
{
    perror("Problem avec malloc");
    exit(EXIT_FAILURE);
}

void    fractol_init(t_fractol *fractol)
{
    fractol->mlx_connection = mlx_init();
    if (!fractol->mlx_connection)
        malloc_error();
    fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
    if (!fractol->mlx_window)
    {
        mlx_destroy_display(fractol->mlx_connection);
        free(fractol->mlx_window);
        malloc_error();
    }
    fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
    if (!fractol->img.img_ptr)
    {
        mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
        mlx_destroy_display(fractol->mlx_connection);
        free(fractol->mlx_window);
        malloc_error();
    }
    fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
    data_init(fractol);
}