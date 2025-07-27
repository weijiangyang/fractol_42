/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:07:26 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/27 12:59:54 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h> 
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Usage:\n\t./fractol mandelbrot\n \
	./fractol burning_ship \n\t./fractol julia <v1> <v2>\n"
# define WIDTH	800
# define  HEIGHT	800
# define  BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300
# define BUTTON1 1
# define BUTTON2 2
# define BUTTON3 3
# define BUTTON4 4
# define BUTTON5 5

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_scale
{
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}	t_scale;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	t_scale	scale_x;
	t_scale	scale_y;
}				t_fractal;

int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atodbl(char *s);
void		fractal_init(t_fractal *fractal);
int			fractal_render(t_fractal *fractal);
double		map(double unscaled_num, t_scale scale);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif
