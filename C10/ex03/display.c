/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_same_line(t_dump *dump)
{
	int	i;

	if (!dump->has_previous || dump->length != 16)
		return (0);
	i = 0;
	while (i < 16)
	{
		if (dump->line[i] != dump->previous[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_bytes(t_dump *dump)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < dump->length)
			ft_put_hex(dump->line[i], 2);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		if (i++ == 7)
			write(1, " ", 1);
	}
}

void	ft_print_ascii(t_dump *dump)
{
	int		i;
	char	character;

	i = 0;
	write(1, "|", 1);
	while (i < dump->length)
	{
		character = dump->line[i++];
		if (character < 32 || character > 126)
			character = '.';
		write(1, &character, 1);
	}
	write(1, "|\n", 2);
}

void	ft_print_line(t_dump *dump)
{
	int	i;

	if (ft_same_line(dump))
	{
		if (!dump->repeated)
			write(1, "*\n", 2);
		dump->repeated = 1;
		return ;
	}
	ft_put_hex(dump->offset, 8);
	write(1, "  ", 2);
	ft_print_bytes(dump);
	ft_print_ascii(dump);
	i = 0;
	while (i < dump->length)
	{
		dump->previous[i] = dump->line[i];
		i++;
	}
	dump->has_previous = 1;
	dump->repeated = 0;
}
