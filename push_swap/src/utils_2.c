/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:47:50 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/17 13:48:03 by anggalle         ###   ########.fr       */
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
