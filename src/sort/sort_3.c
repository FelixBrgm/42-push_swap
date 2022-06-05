/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:55:21 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 18:23:51 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list **sort_3(t_stack *stack)
{
	t_list **head = NULL;
	t_stack* temp;
	int a;
	int b;
	int c;
	
	temp = stack_create_indexed(stack);
	if (temp->count != 3)
		return (NULL);
	head = ft_calloc(1, sizeof(t_list *));
	
	a = temp->numbers[temp->index + 2];
	b = temp->numbers[temp->index + 1];
	c = temp->numbers[temp->index];
	
	if (a == 1 && b == 3 && c == 2)
	{
		stack_ra(temp, head);
		stack_sa(temp, head);
		stack_rra(temp, head);
	}
	else if (a == 2 && b == 1 && c == 3)
		stack_sa(temp,head);
	else if (a == 2 && b == 3 && c == 1)
		stack_rra(temp,head);
	else if (a == 3 && b == 1 && c == 2)
		stack_ra(temp,head);
	else if (a == 3 && b == 2 && c == 1)
	{
		stack_ra(temp,head);
		stack_sa(temp,head);		
	}
	return (head);
}
