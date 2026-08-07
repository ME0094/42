/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	t_puzzle	puzzle;

	if (argc != 2 || !parse_clues(argv[1], puzzle.clues))
	{
		print_error();
		return (1);
	}
	if (!solve(&puzzle, 0))
	{
		print_error();
		return (1);
	}
	print_grid(puzzle.grid);
	return (0);
}
