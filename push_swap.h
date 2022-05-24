/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:31 by fbruggem          #+#    #+#             */
/*   Updated: 2022/05/22 16:50:04 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#include <stdlib.h>
#include "includes/libft/libft.h"

// TESTING
#include <stdio.h>
// TESTING

typedef struct s_stack
{
	int	*numbers;
	int index;
	int length;
	int count;
}				t_stack;


int		check_input(char **argv);

t_stack	*create_stack(int length);
int		add_number(t_stack *stack, int number);
void	stack_check(t_stack *stack);

// Stack Operations
void stack_swap(t_stack *stack);
int stack_push(t_stack *src, t_stack *dest);
int stack_rotate(t_stack *stack);
int stack_rotate_reverse(t_stack *stack);
#endif