/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "flood_fill.h"

static void	fill(char **tab, t_point size, t_point pos, char target)
{
	t_point	next;

	if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y
		|| tab[pos.y][pos.x] != target)
		return ;
	tab[pos.y][pos.x] = 'F';
	next.x = pos.x + 1;
	next.y = pos.y;
	fill(tab, size, next, target);
	next.x = pos.x - 1;
	fill(tab, size, next, target);
	next.x = pos.x;
	next.y = pos.y + 1;
	fill(tab, size, next, target);
	next.y = pos.y - 1;
	fill(tab, size, next, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
