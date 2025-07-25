/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:55:22 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/25 11:43:06 by weiyang          ###   ########.fr       */
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

double	ft_atodbl_1(char *s)
{
	double	div;
	double	frac;

	div = 10.0;
	frac = 0.0;
	while (*s >= '0' && *s <= '9')
	{
		frac += (*s - '0') / div;
		div *= 10.0;
		s++;
	}
	return (frac);
}

double	ft_atodbl(char *s)
{
	double	result;
	double	frac;
	int		sign;

	result = 0.0;
	frac = 0.0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10.0 + (*s - '0');
		s++;
	}
	if (*s++ == '.')
		frac += ft_atodbl_1(s);
	return (sign * (result + frac));
}
