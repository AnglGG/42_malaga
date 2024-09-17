/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:33:24 by anggalle          #+#    #+#             */
/*   Updated: 2024/09/14 20:33:24 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add(t_stack	**list_ref, int new_value)
{
	t_stack	*new_node;
	t_stack	*last;
	int		index;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	last = *list_ref;
	new_node->value = new_value;
	if (*list_ref == NULL)
	{
		*list_ref = new_node;
		return ;
	}
	index = 1;
	while (last->next != NULL)
	{
		last = last->next;
		index++;
	}
	new_node->index = index;
	last->next = new_node;
}

int	hasduplicates(t_stack	*list)
{
	t_stack	*current;
	t_stack	*checker;

	current = list;
	while (current != NULL && current->next != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
			{
				ft_error();
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

void	one_arg(char *array, t_stack **list)
{
	char	**tokens;
	char	*token;
	int		j;
	int		i;

	tokens = ft_split(array, ' ');
	j = 0;
	if (!tokens)
		ft_error();
	while (tokens[j] != NULL)
	{
		token = tokens[j];
		i = 0;
		while (token[i] != '\0')
		{
			if (!ft_isdigit(token[i]) && token[i] != '-'
				&& token[i] != '+')
				ft_error();
			i++;
		}
		ft_add(list, ft_atoi(token));
		j++;
	}
	j = 0;
	ft_free(tokens);
}

void	various_args(int ac, char **av, t_stack **list)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-'
				&& av[i][j] != '+')
			{
				ft_error();
			}
			j++;
		}
		j = 0;
		ft_add(list, ft_atoi(av[i]));
		i++;
	}
}

void	check_args(int ac, char **av, t_stack **list)
{
	if (ac == 2)
	{
		one_arg(av[1], list);
		hasduplicates(*list);
		assign_indexes(*list);
	}
	else if (ac > 2)
	{
		various_args(ac, av, list);
		hasduplicates(*list);
		assign_indexes(*list);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
