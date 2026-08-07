/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	len;
	int	*a;
	int	i;

	i = 0;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	a = malloc(sizeof(int) * len);
	if (!a)
		return (0);
	while (i < len)
	{
		a[i++] = end;
		if (end < start)
			end++;
		else
			end--;
	}
	return (a);
}
