/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:51:10 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 13:30:25 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

typedef struct s_vars
{
	int		fastes_way_rotate;
	int		max_index;
	int		max_number;
	int		i;
}				t_vars;

void	sort_basic_helper_1(t_vars *vars, t_stack *a)
{
	vars->max_index = 0;
	vars->i = 0;
	vars->max_number = a->numbers[a->index];
	while (vars->i < a->count)
	{
		if (a->numbers[a->index + vars->i] < vars->max_number)
		{
			vars->max_index = vars->i;
			vars->max_number = a->numbers[a->index + vars->i];
		}
		vars->i++;
	}
}

void	sort_basic_helper_2(t_vars *vars, t_list **head, t_stack *a, t_stack *b)
{
	vars->fastes_way_rotate = 1;
	if (a->count / 2 > vars->max_index)
		vars->fastes_way_rotate = 0;
	if (vars->fastes_way_rotate)
	{
		while (a->numbers[a->index + a->count - 1] != vars->max_number)
			stack_ra(a, head);
	}
	else
	{
		while (a->numbers[a->index + a->count - 1] != vars->max_number)
			stack_rra(a, head);
	}
	stack_pb(a, b, head);
}

t_list	**sort_basic(t_stack *stack)
{
	t_list	**head;
	t_stack	*a;
	t_stack	*b;
	t_vars	vars;

	head = ft_calloc(1, sizeof(t_list *));
	if (!head)
		return (NULL);
	a = stack_duplicate(stack);
	b = stack_create(stack->length / 3);
	while (a->count > 0)
	{
		sort_basic_helper_1(&vars, a);
		sort_basic_helper_2(&vars, head, a, b);
	}
	while (b->count > 0)
		stack_pa(a, b, head);
	stack_free(a);
	stack_free(b);
	return (head);
}
