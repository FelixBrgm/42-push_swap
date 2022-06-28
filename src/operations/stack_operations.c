/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:46:16 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 21:54:36 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	stack_swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->numbers)
		return (-1);
	stack_check(stack);
	temp = stack->numbers[stack->index + stack->count - 2];
	stack->numbers[stack->index + stack->count - 2]
		= stack->numbers[stack->index + stack->count - 1];
	stack->numbers[stack->index + stack->count - 1] = temp;
	return (0);
}

int	stack_push(t_stack *src, t_stack *dest)
{
	if (!src || !src->numbers || !dest || !dest->numbers)
		return (-1);
	if (src->count <= 0)
		return (-1);
	stack_check(src);
	stack_check(dest);
	dest->numbers[dest->index + dest->count]
		= src->numbers[src->index + src->count -1];
	dest->count++;
	src->count--;
	return (0);
}

int	stack_rotate(t_stack *stack)
{
	if (!stack || !stack->numbers)
		return (-1);
	stack_check(stack);
	stack->index--;
	stack->numbers[stack->index] = stack->numbers[stack->index + stack->count];
	return (0);
}

int	stack_rotate_reverse(t_stack *stack)
{
	if (!stack || !stack->numbers)
		return (-1);
	stack_check(stack);
	stack->numbers[stack->index + stack->count] = stack->numbers[stack->index];
	stack->index++;
	return (0);
}
