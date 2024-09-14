/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:16 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/14 20:34:17 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlastr(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	rotate(t_stack **list)
{
	t_stack	*node;

	node = NULL;
	if (*list != NULL)
	{
		node = *list;
		*list = (*list)->next;
		node->next = NULL;
		ft_lstlastr(*list)->next = node;
	}
}

void	ra(t_stack **list)
{
	rotate(list);
}

void	rb(t_stack **list)
{
	rotate(list);
}

void	rr(t_stack **list1, t_stack **list2)
{
	rotate(list1);
	rotate(list2);
}
