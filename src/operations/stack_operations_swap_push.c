/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_swap_push.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:06:26 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 11:36:48 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_sa(t_stack *stack, t_list **head)
{
	stack_swap(stack);
	ft_lstadd_back(head, operation_create("sa"));
}

void	stack_sb(t_stack *stack, t_list **head)
{
	if(!stack_swap(stack))
		ft_lstadd_back(head, operation_create("sb"));
}

void	stack_pa(t_stack *a, t_stack *b, t_list **head)
{
	if(!stack_push(b,a))
		ft_lstadd_back(head, operation_create("pa"));
}

void	stack_pb(t_stack *a, t_stack *b, t_list **head)
{
	if(!stack_push(a,b))
		ft_lstadd_back(head, operation_create("pb"));
}