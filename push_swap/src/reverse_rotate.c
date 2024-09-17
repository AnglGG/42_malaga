/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:09 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/17 16:50:56 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lstunlast(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = NULL;
	tmp = lst;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp2 = tmp->next;
		if (tmp2->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	reverse_rotate(t_stack **list)
{
	t_stack	*node;

	node = NULL;
	if (*list != NULL)
	{
		node = ft_lstlastr(*list);
		ft_lstunlast(*list)->next = NULL;
		node->next = *list;
		*list = node;
	}
}

void	rra(t_stack **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}

void	rrb(t_stack **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}

void	rrr(t_stack **list1, t_stack **list2)
{
	reverse_rotate(list1);
	reverse_rotate(list2);
	ft_printf("rrr\n");
}
