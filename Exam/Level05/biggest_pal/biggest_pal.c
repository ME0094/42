/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	is_palindrome(char *str, int start, int end)
{
	while (start < end)
	{
		if (str[start] != str[end])
			return (0);
		start++;
		end--;
	}
	return (1);
}

static void	find_biggest(char *str, int length, int *pos, int *best)
{
	int	size;
	int	start;

	size = 1;
	while (size <= length)
	{
		start = 0;
		while (start + size <= length)
		{
			if (size >= *best && is_palindrome(str, start, start + size - 1))
			{
				*best = size;
				*pos = start;
			}
			start++;
		}
		size++;
	}
}

int	main(int ac, char **av)
{
	int	length;
	int	best;
	int	position;

	length = 0;
	best = 0;
	position = 0;
	if (ac == 2)
	{
		while (av[1][length])
			length++;
		find_biggest(av[1], length, &position, &best);
		write(1, av[1] + position, best);
	}
	write(1, "\n", 1);
	return (0);
}
