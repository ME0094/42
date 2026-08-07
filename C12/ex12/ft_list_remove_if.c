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

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*victim;

	while (*begin_list != 0 && cmp((*begin_list)->data, data_ref) == 0)
	{
		current = *begin_list;
		*begin_list = (*begin_list)->next;
		free_fct(current->data);
		free(current);
	}
	current = *begin_list;
	while (current != 0 && current->next != 0)
	{
		if (cmp(current->next->data, data_ref) == 0)
		{
			victim = current->next;
			current->next = victim->next;
			free_fct(victim->data);
			free(victim);
		}
		else
			current = current->next;
	}
}
