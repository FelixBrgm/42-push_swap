/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:47:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 12:22:32 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list **stack_sort(t_stack *stack)
{
	t_list **head_min;
	t_list **head_basic;
	t_list **head_radix;
	t_list **head_3;

	head_min = NULL;
	if (stack_is_sorted(stack))
		return (head_min);
	head_basic = sort_basic(stack);
	if (head_basic)
		head_min = head_basic;
	head_radix = sort_radix(stack);
	if (head_radix && ft_lstsize(*head_min) > ft_lstsize(*head_radix))
		head_min = head_radix;
	head_3 = sort_3(stack);
	if (head_3 && ft_lstsize(*head_min) > ft_lstsize(*head_3))
		head_min = head_3;
	if (head_basic && head_basic != head_min)
	{
		operations_free(*head_basic);
		free(head_basic);
	}
	if (head_radix && head_radix != head_min)
	{
		operations_free(*head_radix);
		free(head_radix);
	}
	if (head_3 && head_3 != head_min)
	{
		operations_free(*head_3);
		free(head_3);
	}
	return (head_min);
}