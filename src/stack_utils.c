/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:39:48 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 18:16:25 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/// REMOVE
void	stack_print(t_stack *stack)
{
	int i = 0;

	printf("| ");
	while (i < stack->length)
	{
		if (i < stack->index || i >= stack->index + stack->count)
			printf("   ");
		else
			printf("%i, ",stack->numbers[i]);
		i++;
	}
	printf("|\n");
}
//// REMOVE

t_stack	*stack_duplicate(t_stack *stack)
{
	t_stack *new;
	int		i;
	
	if (!stack || !stack->numbers)
		return (NULL);
	
	i = 0;
	new = NULL;
	new = stack_create(stack->length/3);
	if (!new)
		return (NULL);
	while(i < stack->count)
	{
		stack_add(new, stack->numbers[stack->index + stack->count -1 - i ]);
		i++;
	}
	return (new);
}

t_stack *stack_create_indexed(t_stack *stack)
{
	t_stack *res;
	int		i;
	int		j;
	int 	last_number;
	int		current_number;
	int		current_index;
	int		is_set;

	res = stack_duplicate(stack);
	i = 0;
	j = 0;
	while (i < stack->count)
	{
		if(current_number > stack->numbers[stack->index + i])
		{
			current_number = stack->numbers[stack->index + i];
			current_index = i;
		}
		i++;
	}
	res->numbers[res->index + current_index] = j++;
	last_number = current_number;
	i = 0;
	while (j <= stack->count)
	{
		i = 0;
		current_number = 2147483647;
		current_index = 0;
		is_set = 0;
		while(i < stack->count)
		{
			if (stack->numbers[stack->index + i] > last_number && stack->numbers[stack->index + i] < current_number)
			{
				current_number = stack->numbers[stack->index + i];
				current_index = i;
				is_set = 1;
			}
			i++;
		}
		//printf("Current: I: %i | N: %i | J: %i\n",current_index, current_number, j);
		if (is_set)	
			res->numbers[res->index + current_index] = j;
		last_number = current_number;
		j++;
	}
	return (res);
}

int stack_is_sorted(t_stack *stack)
{
	int i;

	if (!stack || !stack->numbers)
		return (0);	
	i = 0;
	while (i < stack->count -1)
	{
		if (stack->numbers[stack->index + i] < stack->numbers[stack->index + i + 1])
			return (0);
		i++;
	}
	return (1);
}

