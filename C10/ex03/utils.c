/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	ft_put_hex(unsigned int value, int digits)
{
	char	*base;
	char	result[8];
	int		count;

	base = "0123456789abcdef";
	count = digits;
	while (digits > 0)
	{
		digits--;
		result[digits] = base[value % 16];
		value /= 16;
	}
	write(1, result, count);
}

void	ft_error(char *program, char *name)
{
	write(2, basename(program), ft_strlen(basename(program)));
	write(2, ": ", 2);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}
