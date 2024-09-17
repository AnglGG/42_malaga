/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:25 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/17 13:55:38 by anggalle         ###   ########.fr       */
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
int ft_lowest_cost(t_stack *list)
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

void	ft_move(t_stack **list_a, t_stack **list_b)
{
	int	tmp;

	tmp = ft_lowest_cost(*list_b);
	while ((*list_b)->pos != tmp)
		*list_b = (*list_b)->next;
	while ((*list_a)->pos != (*list_b)->target_pos)
		*list_a = (*list_a)->next;
	while ((*list_b)->pos != 0 && (*list_a)->pos != 0)
	{
		if ((*list_a)->cost > 0 && (*list_b)->cost > 0)
		{
			rr(list_a, list_b);
			(*list_a)->cost --;
			(*list_b)->cost --;
		}
		else if ((*list_a)->cost < 0 && (*list_b)->cost < 0)
		{
			rrr(list_a, list_b);
			(*list_a)->cost ++;
			(*list_b)->cost ++;
		}
		else
		{
			if ((*list_a)->cost < 0 && (*list_b)->cost > 0)
			{
				rra(list_a);
				rb(list_b);
				(*list_a)->cost ++;
				(*list_b)->cost --;
			}
			else
			{
				ra(list_b);
				rrb(list_a);
				(*list_a)->cost --;
				(*list_b)->cost ++;
			}
		}
		
	}
	while ((*list_a)->cost > 0)
	{
		(*list_a)->cost --;
		ra(list_a);
	}
	while ((*list_a)->cost < 0)
	{
		ra(list_a);
		(*list_a)->cost ++;
	}
	while ((*list_b)->cost > 0)
	{
		rb(list_b);
		(*list_b)->cost --;
	}
	while ((*list_b)->cost < 0)
	{
		rb(list_b);
		(*list_b)->cost ++;
	}
}

void	ft_sorting(t_stack **list_a, t_stack **list_b)
{
	ft_pass(list_a, list_b);
	three_algorithm(list_a);
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
}