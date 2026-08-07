/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

typedef struct s_puzzle
{
	int	clues[16];
	int	grid[4][4];
}	t_puzzle;

int		parse_clues(char *input, int clues[16]);
int		solve(t_puzzle *puzzle, int position);
int		completed_lines_are_valid(t_puzzle *puzzle, int row, int column);
void	print_grid(int grid[4][4]);
void	print_error(void);

#endif
