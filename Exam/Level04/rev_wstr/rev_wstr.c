/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	print_words(char *str)
{
	int	end;
	int	start;
	int	first;

	first = 1;
	end = 0;
	while (str[end])
		end++;
	while (end > 0)
	{
		while (end > 0 && (str[end - 1] == ' ' || str[end - 1] == '\t'))
			end--;
		start = end;
		while (start > 0 && str[start - 1] != ' ' && str[start - 1] != '\t')
			start--;
		if (!first)
			write(1, " ", 1);
		write(1, str + start, end - start);
		first = 0;
		end = start;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_words(av[1]);
	write(1, "\n", 1);
	return (0);
}
