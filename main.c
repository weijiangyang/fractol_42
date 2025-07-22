/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:56:29 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/22 08:56:31 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"



int main(int ac, char **av)
{
    t_fractol      fractol;

    if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
        || (ac == 4 && !ft_strncmp(av[1], "Julia", 5)))
    {
        fractol.name = av[1];
        fractol_init(&fractol);
        //fractol_render(&fractol);
        mlx_loop(fractol.mlx_connection);

    }
    else
    {
        ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
