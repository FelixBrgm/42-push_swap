/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:55:21 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 11:03:43 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list **sort_3(t_stack *stack)
{
	t_list **head;
	t_stack* temp;
	int a;
	int b;
	int c;
	
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
	a = temp->numbers[temp->index + 2];
	b = temp->numbers[temp->index + 1];
	c = temp->numbers[temp->index];
	
	if ( b == a + 2 && c ==  a + 1)
	{
		stack_ra(temp, head);
		stack_sa(temp, head);
		stack_rra(temp, head);
	}
	else if (a == b + 1 && c == b + 2)
		stack_sa(temp,head);
	else if (a == c + 1 && b == c + 2)
		stack_rra(temp,head);
	else if (a == b + 2 && c == b + 1)
		stack_ra(temp,head);
	else if (a == c + 2 && b == c + 1)
	{
		stack_ra(temp,head);
		stack_sa(temp,head);		
	}
	stack_free(temp);
	return (head);
}
