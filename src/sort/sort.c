/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:47:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/04 15:35:22 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list **stack_sort(t_stack *stack)
{
	// TODO: heck if sortet and for 2 3 4 5 a seperate algorytm
	t_list **head_radix;

	head_radix = sort_radix(stack);
	return (head_radix);
}