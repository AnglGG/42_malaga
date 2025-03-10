/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anggalle <anggalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 02:19:30 by anggalle          #+#    #+#             */
/*   Updated: 2025/03/10 16:51:13 by anggalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_stack
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}	t_stack;

int				error_syntax(char *argv);
int				error_duplicate(t_stack *a, int n);
int				stack_len(t_stack *stack);
int				ft_atoi_2(const char *str, t_stack **a);

bool			stack_sorted(t_stack *stack);

char			**split(char *s, char c);

t_stack			*get_cheapest(t_stack *stack);
t_stack			*find_last(t_stack *stack);
t_stack			*find_min(t_stack *stack);
t_stack			*find_max(t_stack *stack);

void			init_stack_a(t_stack **a, char **argv, int argc);
void			free_stack(t_stack **stack);
void			ft_errors(t_stack **a);
void			init_nodes_a(t_stack *a, t_stack *b);
void			init_nodes_b(t_stack *a, t_stack *b);
void			assign_indexes(t_stack *stack);
void			ft_lowest_cost(t_stack *stack);
void			prep_for_push(t_stack **s, t_stack *n, char c);
void			sa(t_stack **a, bool print);
void			sb(t_stack **b, bool print);
void			ss(t_stack **a, t_stack **b, bool print);
void			ra(t_stack **a, bool print);
void			rb(t_stack **b, bool print);
void			rr(t_stack **a, t_stack **b, bool print);
void			rra(t_stack **a, bool print);
void			rrb(t_stack **b, bool print);
void			rrr(t_stack **a, t_stack **b, bool print);
void			pa(t_stack **a, t_stack **b, bool print);
void			pb(t_stack **b, t_stack **a, bool print);
void			sort_three(t_stack **a);
void			sort_stacks(t_stack **a, t_stack **b);
void			free_argv(char **argv, int argc);
void			append_node(t_stack **stack, int n);

#endif