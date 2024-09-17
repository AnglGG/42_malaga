/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:00 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/17 16:50:25 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **list1, t_stack **list2)
{
	t_stack	*node;

	node = NULL;
	if (*list1 != NULL)
	{
		node = *list1;
		*list1 = (*list1)->next;
		node->next = *list2;
		*list2 = node;
	}
}

void	pb(t_stack **list1, t_stack **list2)
{
	push(list1, list2);
	ft_printf("pb\n");
}

void	pa(t_stack **list1, t_stack **list2)
{
	push(list2, list1);
	ft_printf("pa\n");
}
