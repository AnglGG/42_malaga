/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:36 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/14 20:34:37 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_higher_middle(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *list;
	node2 = node1->next;
	node3 = node2->next;
	if (node3->index > node2->index)
		exit(EXIT_SUCCESS);
	else if (node3->index < node2->index)
	{
		if (node1->index < node3->index)
		{
			rra(list);
			sa(list);
		}
		else
			rra(list);
	}
}

void	ft_rest(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *list;
	node2 = node1->next;
	node3 = node2->next;
	if (node1->index > node3->index)
	{
		if (node3->index > node2->index)
			ra(list);
		else
		{
			ra(list);
			sa(list);
		}
	}
	else
		sa(list);
}

void	three_algorithm(t_stack **list)
{
	t_stack	*node1;
	t_stack	*node2;
	t_stack	*node3;

	node1 = *list;
	node2 = node1->next;
	node3 = node2->next;
	if (node2->index > node1->index)
		ft_higher_middle(list);
	else if (node1->index > node2->index)
		ft_rest(list);
}
