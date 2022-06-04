/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:34:41 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 10:48:52 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	stack_ss(t_stack *a, t_stack *b, t_list **head)
{
	stack_sa(a,head);
	stack_sb(b,head);
}

void	stack_rr(t_stack *a, t_stack *b, t_list **head)
{
	stack_ra(a,head);
	stack_rb(b,head);
}

void	stack_rrr(t_stack *a, t_stack *b, t_list **head)
{
	stack_rra(a,head);
	stack_rrb(b,head);
}