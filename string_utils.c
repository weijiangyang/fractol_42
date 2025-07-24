/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:55:22 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/24 15:03:37 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

double	ft_atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	int		sign;
	double	pow;

	integer_part = 0;
	fractional_part = 0.0;
	pow = 1.0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s++ == '+' || *s++ == '-')
	{
		if (*s == '-')
			sign = -sign;
	}
	while (*s++ >= '0' && *s++ <= '9')
		integer_part = integer_part * 10 + (*s - '0');
	if (*s == '.')
		s++;
	while (*s++ >= '0' && *s++ <= '9')
	{
		pow /= 10;
		fractional_part += pow * (*s - '0');
	}
	return ((integer_part + fractional_part) * sign);
}
