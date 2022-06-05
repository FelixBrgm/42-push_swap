/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:22:43 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 18:32:52 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_create(int length)
{
	t_stack	*stack;

	if (length <= 0)
		return (NULL);
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->numbers = ft_calloc(length * 3, sizeof(int));
	if (!stack->numbers)
	{
		free(stack);
		return (NULL);
	}
	stack->index = length * 2;
	stack->length = length * 3;
	stack->count = 0;
	return (stack);
}

t_stack	*stack_create_argv(char **argv)
{
	t_stack	*stack;
	int		i;

	if (!argv)
		return (NULL);
	stack = stack_create(ft_2ptrlen((void **) argv));
	if (!stack)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		stack_add(stack, ft_atoi(argv[i]));
		i++;
	}
	return (stack);
}

void	stack_add(t_stack *stack, int number)
{
	if (!stack)
		exit(-1);
	if (stack->count >= stack->length)
		exit (-1);
	stack_check(stack);
	stack->index--;
	stack->count++;
	stack->numbers[stack->index] = number;
}

void	stack_check(t_stack *stack)
{
	int	i;
	int	temp;
	int	diff;

	if (!stack || !stack->numbers)
		exit (-1);
	if (stack->index <= 0 || stack->index + stack->count >= stack->length)
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

void	stack_free(t_stack *stack)
{
	if (stack)
	{
		if (stack->numbers)
			free(stack->numbers);
		free(stack);
	}
}
