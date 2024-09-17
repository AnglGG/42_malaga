/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:25 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/17 20:28:34 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pass(t_stack **list_a, t_stack **list_b)
{
	double	average;
	int		total;

	total = count_values(*list_a);
	*list_b = NULL;
	average = ft_average(*list_a);
	while (total > 3)
	{
		if ((*list_a)->index < average)
		{
			pb(list_a, list_b);
			total--;
		}
		else if (verify_index(*list_a, average) == 0)
		{
			total--;
			pb(list_a, list_b);
		}
		else
			ra(list_a);
	}
}

void	target_pos(t_stack *list_a, t_stack *list_b)
{
	t_stack	*current;
	t_stack	*compare;
	int		nearest;

	current = list_b;
	while (current != NULL)
	{
		nearest = nearest_index(current->index, list_a);
		compare = list_a;
		while (compare != NULL)
		{
			if (compare->index == nearest)
			{
				current->target_pos = compare->pos;
				break ;
			}
			compare = compare->next;
		}
		current = current->next;
	}
}

void	ft_costs(t_stack *list)
{
	t_stack	*node;
	int		len;

	node = list;
	len = count_values(list);
	while (node)
	{
		if (node->pos > len / 2)
			node->cost = -1 * (len - node->pos);
		else
			node->cost = node->pos;
		node = node->next;
	}
}

void	ft_move(t_stack **list_a, t_stack **list_b)
{
	int		tmp;
	t_stack	*node_a;
	t_stack	*node_b;

	tmp = ft_lowest_cost(*list_b);
	node_b = *list_b;
	while (node_b->pos != tmp)
		node_b = node_b->next;
	node_a = *list_a;
	while (node_a->pos != node_b->target_pos)
		node_a = node_a->next;
	while (node_b->cost != 0 || node_a->cost != 0)
	{
		ft_same_sign(node_a, node_b);
		ft_different_sign(list_a, list_b, node_a, node_b);
	}
}

void	ft_sorting(t_stack **list_a, t_stack **list_b)
{
	assign_pos(*list_a);
	assign_pos(*list_b);
	target_pos(*list_a, *list_b);
	ft_costs(*list_a);
	ft_costs(*list_b);
	ft_total_cost(list_a, list_b);
	while (*list_b)
	{
		ft_move(list_a, list_b);
		pa(list_a, list_b);
		assign_pos(*list_a);
		assign_pos(*list_b);
		target_pos(*list_a, *list_b);
		ft_costs(*list_a);
		ft_costs(*list_b);
		ft_total_cost(list_a, list_b);
	}
	final_sort(list_a);
}
