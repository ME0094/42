/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_base_length(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_write_base(long number, char *base, int base_length)
{
	char	digit;

	if (number >= base_length)
		ft_write_base(number / base_length, base, base_length);
	digit = base[number % base_length];
	write(1, &digit, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;
	long	number;

	base_length = ft_base_length(base);
	if (base_length == 0)
		return ;
	number = nbr;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	ft_write_base(number, base, base_length);
}
