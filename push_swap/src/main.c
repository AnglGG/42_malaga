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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	check_args(ac, av, &a);
	ft_printf("A list\n");
	printlist(a);
	ft_printf("B list\n");
	printlist(b);
	if (count_values(a) == 3)
		three_algorithm(&a);
	else
	{
		ft_sorting(&a, &b);
	}
	ft_printf("A list\n");
	printlist(a);
	ft_printf("B list\n");
	printlist(b);
	return (0);
}
