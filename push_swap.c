/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:34 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/22 16:58:30 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printStack(t_stack *stack)
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

int main()
{
	//t_list **list;
	// if (argc <= 1)
	// 	exit(-1);	
	// if (check_input(argv))
	// {
	// 	ft_putstr_fd("Error\n",1);
	// 	exit(-1);
	// }
	
	
	// printf("OK!\n");
	int i = 0;
	t_stack *a = create_stack(5);
	//t_stack *b = create_stack(3);
	printf("\n\n\n\n\n");
	add_number(a, 4);

	while (i++ < 4)
	{
		add_number(a, 2);
	}
	// printStack(a);
	// printf("Stack: Length: %i | Count: %i | Index: %i\n\n",a->length, a->count, a->index);
	// stack_check(a);
	// printStack(a);
	// printf("Stack: Length: %i | Count: %i | Index: %i\n\n",a->length, a->count, a->index);
	while (i++ < 60)
	{
		stack_rotate(a);
		printStack(a);
		//printf("Stack: Length: %i | Count: %i | Index: %i\n\n",a->length, a->count, a->index);
	}
	// add_number(a, 2);
	// add_number(a, 2);
	// add_number(b, 7);
	// printStack(a);
	// printStack(b);
	// stack_push(a,b);
	// printStack(a);
	// printStack(b);
	// t_stack *stack = create_stack(3);
	// printStack(stack);
	// add_number(stack, 5);
	// printStack(stack);
	// add_number(stack, 7);
	// add_number(stack, 7);
	// printStack(stack);
	// stack_swap(stack);
	// printStack(stack);
	// printStack(stack);
	// add_number(stack, 5);
	// printStack(stack);
	// 	add_number(stack, 5);
	// printStack(stack);
	// 	add_number(stack, 5);
	// printStack(stack);
	return (0);
}