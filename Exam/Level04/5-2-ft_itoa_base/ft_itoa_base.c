/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static unsigned int	absolute_value(int value)
{
	if (value < 0)
		return (-(unsigned int)value);
	return ((unsigned int)value);
}

static int	digit_count(unsigned int number, int base)
{
	int	length;

	length = 1;
	while (number >= (unsigned int)base)
	{
		length++;
		number /= base;
	}
	return (length);
}

char	*ft_itoa_base(int value, int base)
{
	unsigned int	n;
	int				neg;
	int				len;
	char			*s;

	if (base < 2 || base > 16)
		return (0);
	neg = value < 0 && base == 10;
	n = absolute_value(value);
	len = digit_count(n, base);
	s = malloc(len + neg + 1);
	if (!s)
		return (0);
	s[len + neg] = '\0';
	while (len)
	{
		s[--len + neg] = "0123456789ABCDEF"[n % base];
		n /= base;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
