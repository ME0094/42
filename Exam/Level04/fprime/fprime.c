/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static void	print_factors(int number)
{
	int	divisor;
	int	first;

	divisor = 2;
	first = 1;
	if (number == 1)
		printf("1");
	while (number > 1)
	{
		if (number % divisor == 0)
		{
			if (!first)
				printf("*");
			printf("%d", divisor);
			first = 0;
			number /= divisor;
		}
		else
			divisor++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_factors(atoi(av[1]));
	printf("\n");
	return (0);
}
