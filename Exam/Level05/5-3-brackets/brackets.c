/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static int	match(char a, char b)
{
	return ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{'
			&& b == '}'));
}

static int	valid(char *s)
{
	char	stack[4096];
	int		top;

	top = 0;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
			stack[top++] = *s;
		else if (*s == ')' || *s == ']' || *s == '}')
		{
			if (!top || !match(stack[--top], *s))
				return (0);
		}
		s++;
	}
	return (top == 0);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		write(1, "\n", 1);
	while (i < ac)
	{
		if (valid(av[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}
