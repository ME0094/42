/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **list, void *ref, int (*cmp)())
{
	t_list	*node;

	while (*list)
	{
		if (cmp((*list)->data, ref) == 0)
		{
			node = *list;
			*list = (*list)->next;
			free(node);
		}
		else
			list = &(*list)->next;
	}
}
