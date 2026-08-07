/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martirod <martirod@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 00:00:00 by martirod          #+#    #+#             */
/*   Updated: 2026/08/07 00:00:00 by martirod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	btree_node_count(t_btree *root)
{
	if (root == 0)
		return (0);
	return (1 + btree_node_count(root->left)
		+ btree_node_count(root->right));
}

void	btree_add_children(t_btree **queue, int *end, t_btree *node)
{
	if (node->left != 0)
		queue[(*end)++] = node->left;
	if (node->right != 0)
		queue[(*end)++] = node->right;
}

void	btree_apply_level(t_queue *queue, int level,
		void (*applyf)(void *, int, int))
{
	int	level_end;
	int	is_first;

	level_end = queue->end;
	is_first = 1;
	while (queue->start < level_end)
	{
		applyf(queue->nodes[queue->start]->item, level, is_first);
		is_first = 0;
		btree_add_children(queue->nodes, &queue->end,
			queue->nodes[queue->start++]);
	}
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue	queue;
	int		level;

	if (root == 0)
		return ;
	queue.nodes = malloc(sizeof(t_btree *) * btree_node_count(root));
	if (queue.nodes == 0)
		return ;
	queue.start = 0;
	queue.end = 1;
	level = 0;
	queue.nodes[0] = root;
	while (queue.start < queue.end)
	{
		btree_apply_level(&queue, level, applyf);
		level++;
	}
	free(queue.nodes);
}
