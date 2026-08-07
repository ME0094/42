/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

static void	clear_memory(unsigned char *memory)
{
	int	i;

	i = 0;
	while (i < 2048)
		memory[i++] = 0;
}

static int	jump(char *code, int i, int direction)
{
	int	depth;

	depth = 1;
	while (depth)
	{
		i += direction;
		if (code[i] == '[')
			depth += direction;
		else if (code[i] == ']')
			depth -= direction;
	}
	return (i);
}

static void	execute(char *code, unsigned char *memory)
{
	int	i;
	int	pointer;

	i = 0;
	pointer = 0;
	while (code[i])
	{
		if (code[i] == '>')
			pointer++;
		else if (code[i] == '<')
			pointer--;
		else if (code[i] == '+')
			memory[pointer]++;
		else if (code[i] == '-')
			memory[pointer]--;
		else if (code[i] == '.')
			write(1, &memory[pointer], 1);
		else if (code[i] == '[' && !memory[pointer])
			i = jump(code, i, 1);
		else if (code[i] == ']' && memory[pointer])
			i = jump(code, i, -1);
		i++;
	}
}

int	main(int ac, char **av)
{
	unsigned char	memory[2048];

	clear_memory(memory);
	if (ac == 2)
		execute(av[1], memory);
	return (0);
}
