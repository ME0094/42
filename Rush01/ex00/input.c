/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	parse_clues(char *input, int clues[16])
{
	int	i;
	int	position;

	i = 0;
	position = 0;
	while (i < 16)
	{
		if (input[position] < '1' || input[position] > '4')
			return (0);
		clues[i] = input[position] - '0';
		position++;
		if (i < 15 && input[position++] != ' ')
			return (0);
		i++;
	}
	return (input[position] == '\0');
}
