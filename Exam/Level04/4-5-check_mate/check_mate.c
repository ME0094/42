/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "check_mate.h"
#include <unistd.h>

static int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	clear_path(t_board *board, t_point from, t_point to)
{
	int	dr;
	int	dc;

	dr = (to.r > from.r) - (to.r < from.r);
	dc = (to.c > from.c) - (to.c < from.c);
	from.r += dr;
	from.c += dc;
	while (from.r != to.r || from.c != to.c)
	{
		if (board->cells[from.r][from.c] != '.')
			return (0);
		from.r += dr;
		from.c += dc;
	}
	return (1);
}

static int	attacks(t_board *board, t_point from)
{
	char	piece;
	int		dr;
	int		dc;

	piece = board->cells[from.r][from.c];
	dr = absolute(board->king.r - from.r);
	dc = absolute(board->king.c - from.c);
	if (piece == 'P')
		return (board->king.r == from.r - 1 && dc == 1);
	if (piece == 'R' && (from.r == board->king.r || from.c == board->king.c))
		return (clear_path(board, from, board->king));
	if (piece == 'B' && dr == dc)
		return (clear_path(board, from, board->king));
	if (piece == 'Q' && (from.r == board->king.r || from.c == board->king.c
			|| dr == dc))
		return (clear_path(board, from, board->king));
	return (0);
}

static void	find_king(t_board *board)
{
	t_point	pos;

	pos.r = 0;
	while (pos.r < board->rows)
	{
		pos.c = 0;
		while (board->cells[pos.r][pos.c])
		{
			if (board->cells[pos.r][pos.c] == 'K')
				board->king = pos;
			pos.c++;
		}
		pos.r++;
	}
}

int	main(int ac, char **av)
{
	t_board	board;
	t_point	pos;

	board.cells = av + 1;
	board.rows = ac - 1;
	find_king(&board);
	pos.r = 0;
	while (pos.r < board.rows)
	{
		pos.c = 0;
		while (board.cells[pos.r][pos.c])
		{
			if (attacks(&board, pos))
				return (write(1, "Success\n", 8), 0);
			pos.c++;
		}
		pos.r++;
	}
	write(1, "Fail\n", 5);
	return (0);
}
