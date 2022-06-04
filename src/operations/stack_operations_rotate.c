/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:22:59 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 10:48:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_ra(t_stack *stack, t_list **head)
{
	if(!stack_rotate(stack))
		ft_lstadd_back(head, operation_create("ra"));
}

void	stack_rb(t_stack *stack, t_list **head)
{
	if(!stack_rotate(stack))
		ft_lstadd_back(head, operation_create("rb"));
}

void	stack_rra(t_stack *stack, t_list **head)
{
	if(!stack_rotate_reverse(stack))
		ft_lstadd_back(head, operation_create("rra"));
}

void	stack_rrb(t_stack *stack, t_list **head)
{
	if(!stack_rotate_reverse(stack))
		ft_lstadd_back(head, operation_create("rrb"));
}
