/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:45:45 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/19 01:21:41 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_different_sign(t_stack **list_a, t_stack **list_b,
			t_stack *node_a, t_stack *node_b)
{
	if (node_a->cost > 0)
	{
		ra(list_a);
		node_a->cost--;
	}
	else if (node_a->cost < 0)
	{
		rra(list_a);
		node_a->cost++;
	}
	else if (node_b->cost > 0)
	{
		rb(list_b);
		node_b->cost--;
	}
	else if (node_b->cost < 0)
	{
		rrb(list_b);
		node_b->cost++;
	}
}

void	ft_same_sign(t_stack **list_a, t_stack **list_b, 
			t_stack *node_a, t_stack *node_b)
{
	if (node_a->cost > 0 && node_b->cost > 0)
	{
		rr(list_a, list_b);
		node_a->cost--;
		node_b->cost--;
	}
	else if (node_a->cost < 0 && node_b->cost < 0)
	{
		rrr(list_a, list_b);
		node_a->cost++;
		node_b->cost++;
	}
}

int	find_pos_first(t_stack	*list)
{
	t_stack	*node;
	int		pos;
	int		len;

	node = list;
	len = count_values(node);
	len = len / 2;
	while (node)
	{
		if (node->index == 1)
			pos = node->pos;
		node = node->next;
	}
	if ((len - pos) < 0)
		return (2);
	else if ((len - pos) > 0)
		return (1);
	else
		return (0);
}

void	final_sort(t_stack **list_a)
{
	int	tmp;

	while ((*list_a)->index != 1)
	{
		tmp = find_pos_first(*list_a);
		if (tmp == 1)
			ra(list_a);
		else if (tmp == 2)
			rra(list_a);
	}
}
