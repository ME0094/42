/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	visible_line(int *line, int step)
{
	int	visible;
	int	highest;
	int	i;

	visible = 0;
	highest = 0;
	i = 0;
	if (step < 0)
		i = 3;
	while (i >= 0 && i < 4)
	{
		if (line[i] > highest)
		{
			highest = line[i];
			visible++;
		}
		i += step;
	}
	return (visible);
}

static int	row_is_valid(t_puzzle *puzzle, int row)
{
	return (visible_line(puzzle->grid[row], 1) == puzzle->clues[8 + row]
		&& visible_line(puzzle->grid[row], -1) == puzzle->clues[12 + row]);
}

static int	column_is_valid(t_puzzle *puzzle, int column)
{
	int	line[4];
	int	row;

	row = 0;
	while (row < 4)
	{
		line[row] = puzzle->grid[row][column];
		row++;
	}
	return (visible_line(line, 1) == puzzle->clues[column]
		&& visible_line(line, -1) == puzzle->clues[4 + column]);
}

int	completed_lines_are_valid(t_puzzle *puzzle, int row, int column)
{
	int	i;

	if (column == 3 && !row_is_valid(puzzle, row))
		return (0);
	if (row == 3 && column == 3)
	{
		i = 0;
		while (i < 4)
			if (!column_is_valid(puzzle, i++))
				return (0);
	}
	return (1);
}
