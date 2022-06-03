/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:31 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/03 10:10:54 by fbruggem         ###   ########.fr       */
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

void print_stack(t_stack *stack);

int		check_input(char **argv);

t_stack	*init_stack(char **arg);
void	free_stack(t_stack *stack);
t_stack	*create_stack(int length);
int		add_number(t_stack *stack, int number);
void	stack_check(t_stack *stack);

// Sort
void sort_stack(t_stack *a, t_stack *b);

// Stack Operations
void	stack_swap(t_stack *stack);
int		stack_push(t_stack *src, t_stack *dest);
int		stack_rotate(t_stack *stack);
int		stack_rotate_reverse(t_stack *stack);
#endif