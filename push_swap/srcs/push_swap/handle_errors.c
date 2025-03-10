/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 02:15:21 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/10 12:36:52 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	error_syntax(char *argv)
{
	int	i;

	i = 0;
	if (!(argv[i] == '+' || argv[i] == '-' || ft_isdigit(argv[i])))
		return (1);
	if ((argv[i] == '+' || argv[i] == '-') && !ft_isdigit(argv[1]))
		return (1);
	i = 1;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_duplicate(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_argv(char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
		{
			if (argv[i])
			{
				free(argv[i]);
				argv[i] = NULL;
			}
			i ++;
		}
		if (argv)
		{
			free(argv);
			argv = NULL;
		}
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		if (current)
		{
			free(current);
		}
		current = tmp;
	}
	*stack = NULL;
}

void	ft_errors(t_stack **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
