/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:51:10 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 11:02:43 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list **sort_basic(t_stack *stack)
{
	t_list **head;
	t_stack *a;
	t_stack *b;
	int fastes_way_rotate;
	int max_index;
	int max_number;
	int i;

	head = ft_calloc(1, sizeof(t_list*));
	if (!head)
		return (NULL);
	a = stack_duplicate(stack);
	b = stack_create(stack->length / 3);
	while (a->count > 0)
	{
		max_index = 0;
		i = 0;
		max_number = a->numbers[a->index];
		while (i < a->count)
		{
			if (a->numbers[a->index + i] < max_number)
			{
				max_index = i;
				max_number = a->numbers[a->index + i];
			}
			i++;
		}
		fastes_way_rotate = 1;
		if (a->count / 2 > max_index)
			fastes_way_rotate = 0;

		
		if (fastes_way_rotate)
		{
			while (a->numbers[a->index + a->count -1] != max_number)
				stack_ra(a,head);
		}
		else 
		{
			while (a->numbers[a->index + a->count-1] != max_number)
				stack_rra(a,head);
		}
		stack_pb(a,b,head);
	}
	while (b->count > 0)
		stack_pa(a,b,head);
	stack_free(a);
	stack_free(b);
	return (head);
}
