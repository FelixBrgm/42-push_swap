/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:54:48 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 13:38:39 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack(char **arg)
{
	t_stack	*stack;
	int		i;

	if (!arg)
		return (NULL);
	stack = create_stack(ft_2ptrlen((void **) arg));
	if (!stack)
		return (NULL);
	i = 1;
	while (arg[i])
	{
		add_number(stack, ft_atoi(arg[i]));
		i++;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->numbers)
			free(stack->numbers);
		free(stack);
	}
}

t_stack *create_stack(int length)
{
	t_stack *stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = ft_calloc(length * 3, sizeof(int));
	if (!stack->numbers)
		return (NULL);
	stack->index = length;
	stack->length = length * 3;
	stack->count = 0;
	
	return (stack);
}

int	add_number(t_stack *stack, int number)
{
	if (stack->count == stack->length)
		return (-1);	
	stack_check(stack);
	stack->index--;
	stack->count++;
	stack->numbers[stack->index] = number;
	return (0);
}

void stack_check(t_stack *stack)
{
	int	i;
	int	temp;
	int diff;
	if (stack->index <= 0)
	{
		i = (stack->length - stack->count) / 2;
		diff = stack->index;
		stack->index = i;
		diff = diff - stack->index;
		temp = stack->count;
		while (temp)
		{
			stack->numbers[i] = stack->numbers[i + diff];
			temp--;
			i++;
		}
		
	}
	if (stack->index + stack->count >= stack->length)
	{
		i = (stack->length - stack->count) / 2;
		diff = stack->index;
		stack->index = i;
		diff = diff - stack->index;
		temp = stack->count;
		while (temp)
		{
			stack->numbers[i] = stack->numbers[i + diff];
			temp--;
			i++;
		}
	}
}