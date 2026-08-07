/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_grid(int grid[4][4])
{
	int		row;
	int		column;
	char	value;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			value = grid[row][column] + '0';
			write(1, &value, 1);
			if (column++ < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		row++;
	}
}
