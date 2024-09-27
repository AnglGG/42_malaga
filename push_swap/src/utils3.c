/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 00:29:16 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/28 00:48:16 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *list_a)
{
	assign_pos(list_a);
	assign_indexes(list_a);
	while (list_a != NULL)
	{
		if (((list_a)->pos + 1) != (list_a)->index)
			return (0);
		list_a = list_a->next;
	}
	return (1);
}
