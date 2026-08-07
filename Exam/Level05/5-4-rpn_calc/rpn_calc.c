/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

static int	read_number(char *str, int *index, int *value)
{
	int				sign;
	unsigned int	number;

	sign = 1;
	number = 0;
	if (str[*index] == '-')
	{
		sign = -1;
		(*index)++;
	}
	if (str[*index] < '0' || str[*index] > '9')
		return (0);
	while (str[*index] >= '0' && str[*index] <= '9')
	{
		number = number * 10 + str[*index] - '0';
		(*index)++;
	}
	*value = (int)number * sign;
	return (1);
}

static int	apply_operator(int *stack, int *top, char op)
{
	int	left;
	int	right;
	int	value;

	if (*top < 2)
		return (0);
	right = stack[--(*top)];
	left = stack[--(*top)];
	if (op == '+')
		value = left + right;
	else if (op == '-')
		value = left - right;
	else if (op == '*')
		value = left * right;
	else if (op == '/' && right)
		value = left / right;
	else if (op == '%' && right)
		value = left % right;
	else
		return (0);
	stack[(*top)++] = value;
	return (1);
}

static int	read_token(char *str, int *index, int *stack, int *top)
{
	int	value;

	if ((str[*index] >= '0' && str[*index] <= '9') || (str[*index] == '-'
			&& str[*index + 1] >= '0' && str[*index + 1] <= '9'))
	{
		if (*top == 4096 || !read_number(str, index, &value))
			return (0);
		if (str[*index] && str[*index] != ' ')
			return (0);
		stack[(*top)++] = value;
		return (1);
	}
	if (str[*index + 1] && str[*index + 1] != ' ')
		return (0);
	if (!apply_operator(stack, top, str[*index]))
		return (0);
	(*index)++;
	return (1);
}

int	main(int ac, char **av)
{
	int	stack[4096];
	int	top;
	int	index;

	top = 0;
	index = 0;
	if (ac != 2)
		return (printf("Error\n"), 0);
	while (av[1][index])
	{
		while (av[1][index] == ' ')
			index++;
		if (!av[1][index])
			break ;
		if (!read_token(av[1], &index, stack, &top))
			return (printf("Error\n"), 0);
	}
	if (top != 1)
		printf("Error\n");
	else
		printf("%d\n", stack[0]);
	return (0);
}
