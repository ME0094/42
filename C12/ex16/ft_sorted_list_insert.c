/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*current;

	new = ft_create_elem(data);
	if (new == 0)
		return ;
	if (*begin_list == 0 || cmp((*begin_list)->data, data) > 0)
	{
		new->next = *begin_list;
		*begin_list = new;
		return ;
	}
	current = *begin_list;
	while (current->next != 0 && cmp(current->next->data, data) <= 0)
		current = current->next;
	new->next = current->next;
	current->next = new;
}
