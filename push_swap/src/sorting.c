/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:34:25 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/14 20:34:26 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_average(t_stack *list)
{
    int sum = 0;
    int count = 0;
    t_stack *current = list;

    while (current != NULL)
    {
        sum += current->index;
        count++;
        current = current->next;
    }

    if (count == 0)
        return 0;

    return (double)sum / count;
}

int verify_index(t_stack **list, int average)
{
    t_stack *current = *list;
    while (current != NULL)
    {
        if (current->index < average)
            return 1;
        current = current->next;
    }
    return 0;
}

void	ft_pass(t_stack **list1, t_stack **list2)
{
	int 	average;
	int		total;

	total = count_values(*list1);
	*list2 = NULL;
	average = ft_average(*list1);
	while (total != 3)
	{
		if ((*list1)->index <= average)
		{
			total--;
			pb(list1, list2);
		}
		else if ((*list1)->index > average && verify_index(list1, average) == 0)
		{
			total--;
			pb(list1, list2);
		}
		else
			ra(list1);	
	}
}

void	ft_sorting(t_stack **list1, t_stack **list2)
{
	ft_pass(list1, list2);
	three_algorithm(list1);
}