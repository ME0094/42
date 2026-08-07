/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	number_length(long value)
{
	int	length;

	length = 1;
	while (value > 9)
	{
		length++;
		value /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	long	v;
	int		len;
	int		neg;
	char	*s;

	v = n;
	neg = v < 0;
	if (v < 0)
		v = -v;
	len = number_length(v) + neg;
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	while (len > neg)
	{
		s[--len] = v % 10 + '0';
		v /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
