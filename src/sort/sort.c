/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:47:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 11:31:45 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list **stack_sort(t_stack *stack)
{
	t_list **head_basic;

	head_basic = sort_basic(stack);
	return (head_basic);
}