/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:31 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/14 20:34:32 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*node;

	node = NULL;
	if (*list != NULL)
	{
		node = *list;
		*list = (*list)->next;
		node->next = (*list)->next;
		(*list)->next = node;
	}
}

void	sa(t_stack **list)
{
	swap(list);
}

void	sb(t_stack **list)
{
	swap(list);
}

void	ss(t_stack **list1, t_stack **list2)
{
	swap(list1);
	swap(list2);
}
