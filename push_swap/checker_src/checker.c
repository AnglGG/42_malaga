/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:09:25 by anggalle          #+#    #+#             */
/*   Updated: 2024/10/02 20:08:07 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>

void execute_instruction(char *instruction, t_stack **a, t_stack **b) {
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(a, 1);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(b, 1);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(a, b, 1);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(a, b, 1);
	else if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ra(a, 1);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		rb(b, 1);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
		rr(a, b, 1);
	else if (ft_strncmp(instruction, "rra\n", 3) == 0)
		rra(a, 1);
	else if (ft_strncmp(instruction, "rrb\n", 3) == 0)
		rrb(b, 1);
	else if (ft_strncmp(instruction, "rrr\n", 3) == 0)
		rrr(a, b, 1);
	else
		write(2, "Error\n", 6);  // Instrucción no válida
}

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char *line;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && (!argv[1][0] || error_syntax(&argv[1][0]))))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	while ((line = get_next_line(0)) > 0)
	{
		execute_instruction(line, &a, &b);
		free(line);
	}
	if (stack_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
