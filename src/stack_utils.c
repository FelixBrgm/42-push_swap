/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:39:48 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 13:08:39 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_vars
{
	int		i;
	int		j;
	int		last_number;
	int		current_number;
	int		current_index;
	int		is_set;
}				t_vars;

void	stack_create_index_helper(t_vars *vars, t_stack *stack, t_stack *res);

t_stack	*stack_duplicate(t_stack *stack)
{
	t_stack	*new;
	int		i;

	if (!stack || !stack->numbers)
		return (NULL);
	i = 0;
	new = NULL;
	new = stack_create(stack->length / 3);
	if (!new)
		return (NULL);
	while (i < stack->count)
	{
		stack_add(new, stack->numbers[stack->index + stack->count -1 - i]);
		i++;
	}
	return (new);
}

t_stack	*stack_create_indexed(t_stack *stack)
{
	t_stack	*res;
	t_vars	vars;

	res = stack_duplicate(stack);
	vars.i = 0;
	vars.j = 0;
	while (vars.i < stack->count)
	{
		if (vars.current_number > stack->numbers[stack->index + vars.i])
		{
			vars.current_number = stack->numbers[stack->index + vars.i];
			vars.current_index = vars.i;
		}
		vars.i++;
	}
	res->numbers[res->index + vars.current_index] = vars.j++;
	vars.last_number = vars.current_number;
	vars.i = 0;
	stack_create_index_helper(&vars, stack, res);
	return (res);
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || !stack->numbers)
		return (0);
	i = 0;
	while (i < stack->count -1)
	{
		if (stack->numbers[stack->index + i]
			< stack->numbers[stack->index + i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	stack_create_index_helper(t_vars *vars, t_stack *stack, t_stack *res)
{
	while (vars->j <= stack->count)
	{
		vars->i = 0;
		vars->current_number = 2147483647;
		vars->current_index = 0;
		vars->is_set = 0;
		while (vars->i < stack->count)
		{
			if (stack->numbers[stack->index + vars->i] > vars->last_number
				&& stack->numbers[stack->index + vars->i]
				< vars->current_number)
			{
				vars->current_number = stack->numbers[stack->index + vars->i];
				vars->current_index = vars->i;
				vars->is_set = 1;
			}
			vars->i++;
		}
		if (vars->is_set)
			res->numbers[res->index + vars->current_index] = vars->j;
		vars->last_number = vars->current_number;
		vars->j++;
	}
}
