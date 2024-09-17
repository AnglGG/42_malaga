/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:50 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/17 16:47:44 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

int	nearest_index(int index1, t_stack *list_a)
{
	int		index2;
	int		lower;
	t_stack	*compare;

	index2 = INT_MAX;
	lower = INT_MAX;
	compare = list_a;
	while (compare != NULL)
	{
		if (compare->index < lower)
			lower = compare->index;
		if (index1 < compare->index && compare->index < index2)
		{
			index2 = compare->index;
		}
		compare = compare->next;
	}
	if (lower == INT_MAX)
		index2 = lower;
	return (index2);
}

void	assign_pos(t_stack *list)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = list;
	while (current != NULL)
	{
		current->pos = i;
		current = current->next;
		i++;
	}
}

int	ft_lowest_cost(t_stack *list)
{
	t_stack	*node;
	int		min_cost;
	int		pos;

	node = list;
	min_cost = INT_MAX;
	pos = -1;
	while (node)
	{
		if (node->total_cost < min_cost)
		{
			min_cost = node->total_cost;
			pos = node->pos;
		}
		node = node->next;
	}
	return (pos);
}

void	ft_total_cost(t_stack **list_a, t_stack **list_b)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		tmp;

	node_b = *list_b;
	while (node_b != NULL)
	{
		node_a = *list_a;
		tmp = node_b->target_pos;
		while (tmp-- > node_a->pos)
			node_a = node_a->next;
		if ((node_b->cost > 0 && node_a->cost > 0)
			|| (node_b->cost < 0 && node_a->cost < 0))
		{
			if (ft_abs(node_b->cost) > ft_abs(node_a->cost))
				node_b->total_cost = ft_abs(node_b->cost);
			else
				node_b->total_cost = ft_abs(node_a->cost);
		}
		else
			node_b->total_cost = ft_abs(node_b->cost) + ft_abs(node_a->cost);
		node_b = node_b->next;
	}
}
