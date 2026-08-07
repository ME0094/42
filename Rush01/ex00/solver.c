/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	value_is_free(t_puzzle *puzzle, int row, int column, int value)
{
	int	i;

	i = 0;
	while (i < column)
		if (puzzle->grid[row][i++] == value)
			return (0);
	i = 0;
	while (i < row)
		if (puzzle->grid[i++][column] == value)
			return (0);
	return (1);
}

int	solve(t_puzzle *puzzle, int position)
{
	int	row;
	int	column;
	int	value;

	if (position == 16)
		return (1);
	row = position / 4;
	column = position % 4;
	value = 1;
	while (value <= 4)
	{
		puzzle->grid[row][column] = value;
		if (value_is_free(puzzle, row, column, value)
			&& completed_lines_are_valid(puzzle, row, column)
			&& solve(puzzle, position + 1))
			return (1);
		value++;
	}
	puzzle->grid[row][column] = 0;
	return (0);
}
