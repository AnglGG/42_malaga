/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:09:25 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/10 16:56:40 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>

static int	manage_error(char *line)
{
	free(line);
	return (1);
}

static void	init_stack_a_checker(t_stack **a, char **argv, int argc, char *line)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			free(line);
			free_argv(argv, argc);
			ft_errors(a);
		}
		n = ft_atoi_2(argv[i], a);
		if (error_duplicate(*a, (int)n))
		{
			free(line);
			free_argv(argv, argc);
			ft_errors(a);
		}
		if (a)
			append_node(a, (int)n);
		i++;
	}
}

void	execute_instruction(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		sa(a, 1);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		sb(b, 1);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
		ss(a, b, 1);
	else if (ft_strncmp(instruction, "pa\n", 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(instruction, "pb\n", 3) == 0)
		pb(b, a, 1);
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
		write(2, "Error\n", 6);
}

void	execute(t_stack *a, t_stack *b, char **argv, int argc)
{
	if (stack_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_argv(argv, argc);
	free_stack(&a);
	free_stack(&b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	line = get_next_line(0);
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && (!argv[1][0])))
		return (manage_error(line));
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a_checker(&a, argv, argc, line);
	}
	else
		init_stack_a_checker(&a, argv + 1, argc, line);
	while (line != NULL)
	{
		execute_instruction(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	execute(a, b, argv, argc);
}
