/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

static void	print_rest(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			i = skip_spaces(str, i);
			if (str[i])
				write(1, " ", 1);
		}
		else
			write(1, &str[i++], 1);
	}
}

static void	rotate(char *str)
{
	int	i;
	int	start;
	int	first_end;

	i = skip_spaces(str, 0);
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	first_end = i;
	i = skip_spaces(str, i);
	print_rest(str, i);
	if (i > first_end)
		write(1, " ", 1);
	write(1, str + start, first_end - start);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		rotate(av[1]);
	write(1, "\n", 1);
	return (0);
}
