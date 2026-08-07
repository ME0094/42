/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	is_word_start(char *str, int i)
{
	return (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t');
}

int	main(int ac, char **av)
{
	int		a;
	int		i;
	char	c;

	a = 1;
	while (a < ac)
	{
		i = 0;
		while (av[a][i])
		{
			c = av[a][i];
			if (c >= 'A' && c <= 'Z')
				c += 32;
			if (c >= 'a' && c <= 'z' && is_word_start(av[a], i))
				c -= 32;
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
		a++;
	}
	if (ac == 1)
		write(1, "\n", 1);
	return (0);
}
