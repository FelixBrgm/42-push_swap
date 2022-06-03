/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felixbruggemann <felixbruggemann@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:02:09 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 23:04:08 by felixbrugge      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void stack_swap(t_stack *stack)
{
	int	temp;
	stack_check(stack);
	temp = stack->numbers[stack->index];
	stack->numbers[stack->index] = stack->numbers[stack->index + 1];
	stack->numbers[stack->index + 1] = temp;
}

int stack_push(t_stack *src, t_stack *dest)
{
	if (src->count <= 0)
		return (-1);	
	stack_check(src);
	stack_check(dest);
	dest->numbers[dest->index + dest->count] = src->numbers[src->index + src->count -1];
	dest->count++;
	src->count--;
	return (0);
}

int stack_rotate_reverse(t_stack *stack)
{
	if (!stack)
		return (-1);
	stack_check(stack);
	stack->numbers[stack->index + stack->count] = stack->numbers[stack->index];
	stack->index++;
	
	return (0);
}

int stack_rotate(t_stack *stack)
{
	if (!stack)
		return (-1);
	stack_check(stack);
	stack->index--;
	stack->numbers[stack->index] = stack->numbers[stack->index + stack->count];
	return (0);
}
