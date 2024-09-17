/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:33:44 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/14 20:33:44 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *node)
{
	while (node != NULL)
	{
		ft_printf("Value: %d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

void	ft_free_list(t_stack *list)
{
	t_stack	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_args(ac, av, &a);
	if (count_values(a) == 3)
		three_algorithm(&a);
	else
	{
		ft_pass(&a, &b);
		three_algorithm(&a);
		ft_sorting(&a, &b);
	}
	ft_free_list(a);
	return (0);
}
