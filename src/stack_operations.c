/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:02:09 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/22 16:49:49 by fbruggem         ###   ########.fr       */
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
	if (src->count <= 0 || dest->count <= 0)
		return (-1);	
	stack_check(src);
	stack_check(dest);
	dest->index--;
	dest->count++;
	dest->numbers[dest->index] = src->numbers[src->index];
	src->index++;
	src->count--;
	return (0);
}

int stack_rotate(t_stack *stack)
{
	if (!stack)
		return (-1);
	stack_check(stack);
	stack->numbers[stack->index + stack->count] = stack->numbers[stack->index];
	stack->index++;
	
	return (0);
}

int stack_rotate_reverse(t_stack *stack)
{
	if (!stack)
		return (-1);
	stack_check(stack);
	stack->numbers[stack->index - 1] = stack->numbers[stack->index + stack->count -1];
	stack->index--;
	
	return (0);
}
