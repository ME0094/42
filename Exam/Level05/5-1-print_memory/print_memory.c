/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <unistd.h>

static void	put_hex(unsigned char value)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, &base[value / 16], 1);
	write(1, &base[value % 16], 1);
}

static void	print_hex_line(const unsigned char *data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
			put_hex(data[i]);
		else
			write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

static void	print_ascii(const unsigned char *data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && i < 16)
	{
		if (data[i] >= 32 && data[i] <= 126)
			write(1, data + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	const unsigned char	*data;
	size_t				offset;
	size_t				remaining;

	data = addr;
	offset = 0;
	while (offset < size)
	{
		remaining = size - offset;
		print_hex_line(data + offset, remaining);
		print_ascii(data + offset, remaining);
		write(1, "\n", 1);
		offset += 16;
	}
}
