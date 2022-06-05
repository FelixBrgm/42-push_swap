/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:55:21 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 18:20:22 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

typedef struct s_vars
{
	int	a;
	int	b;
	int	c;
}				t_vars;

void	sort_3_helper(t_list **head, t_stack *temp, t_vars vars)
{
	if (vars.b == vars.a + 2 && vars.c == vars.a + 1)
	{
		stack_ra(temp, head);
		stack_sa(temp, head);
		stack_rra(temp, head);
	}
	else if (vars.a == vars.b + 1 && vars.c == vars.b + 2)
		stack_sa(temp, head);
	else if (vars.a == vars.c + 1 && vars.b == vars.c + 2)
		stack_rra(temp, head);
	else if (vars.a == vars.b + 2 && vars.c == vars.b + 1)
		stack_ra(temp, head);
	else if (vars.a == vars.c + 2 && vars.b == vars.c + 1)
	{
		stack_ra(temp, head);
		stack_sa(temp, head);
	}
}

t_list	**sort_3(t_stack *stack)
{
	t_list	**head;
	t_stack	*temp;
	t_vars	vars;

	if (stack->count != 3)
		return (NULL);
	temp = stack_create_indexed(stack);
	if (!temp)
		return (NULL);
	head = ft_calloc(1, sizeof(t_list *));
	if (!head)
	{
		stack_free(temp);
		return (NULL);
	}
	vars.a = temp->numbers[temp->index + 2];
	vars.b = temp->numbers[temp->index + 1];
	vars.c = temp->numbers[temp->index];
	sort_3_helper(head, temp, vars);
	stack_free(temp);
	return (head);
}
