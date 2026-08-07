/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	dummy;
	t_list	*tail;

	tail = &dummy;
	while (*begin_list1 != 0 && begin_list2 != 0)
	{
		if (cmp((*begin_list1)->data, begin_list2->data) <= 0)
		{
			tail->next = *begin_list1;
			*begin_list1 = (*begin_list1)->next;
		}
		else
		{
			tail->next = begin_list2;
			begin_list2 = begin_list2->next;
		}
		tail = tail->next;
	}
	if (*begin_list1 != 0)
		tail->next = *begin_list1;
	else
		tail->next = begin_list2;
	*begin_list1 = dummy.next;
}
