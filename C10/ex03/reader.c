/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_feed(t_dump *dump, char *buffer, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dump->line[dump->length++] = buffer[i++];
		if (dump->length == 16)
		{
			ft_print_line(dump);
			dump->offset += 16;
			dump->length = 0;
		}
	}
}

void	ft_finish(t_dump *dump)
{
	if (dump->length > 0)
	{
		ft_print_line(dump);
		dump->offset += dump->length;
	}
	if (dump->offset > 0)
	{
		ft_put_hex(dump->offset, 8);
		write(1, "\n", 1);
	}
}
