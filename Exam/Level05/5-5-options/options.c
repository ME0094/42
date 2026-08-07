/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	usage(void)
{
	write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 35);
}

static int	read_option(char *option, unsigned int *bits)
{
	int	i;

	if (option[0] != '-' || !option[1])
		return (0);
	i = 1;
	while (option[i])
	{
		if (option[i] == 'h')
			return (2);
		if (option[i] < 'a' || option[i] > 'z')
			return (0);
		*bits |= 1u << (option[i] - 'a');
		i++;
	}
	return (1);
}

static void	print_options(unsigned int bits)
{
	int		bit;
	char	value;

	bit = 31;
	while (bit >= 0)
	{
		value = '0';
		if (bits & (1u << bit))
			value = '1';
		write(1, &value, 1);
		if (bit % 8 == 0 && bit)
			write(1, " ", 1);
		bit--;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	unsigned int	bits;
	int				index;
	int				status;

	bits = 0;
	index = 1;
	if (ac == 1)
		return (usage(), 0);
	while (index < ac)
	{
		status = read_option(av[index++], &bits);
		if (status == 2)
			return (usage(), 0);
		if (!status)
			return (write(1, "Invalid Option\n", 15), 0);
	}
	print_options(bits);
	return (0);
}
