/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 08:23:31 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/05 11:05:46 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#	define PUSH_SWAP_H

#include <stdlib.h>
#include "includes/libft/libft.h"

typedef struct s_stack
{
	int	*numbers;
	int index;
	int length;
	int count;
}				t_stack;

// input check
int input_check(char **argv);

// Stack.c
t_stack *stack_create(int length);
t_stack *stack_create_argv(char **argv);
void	stack_add(t_stack *stack, int number);
void	stack_check(t_stack *stack);
void	stack_free(t_stack *stack);

// stack_utils.c
t_stack	*stack_duplicate(t_stack *stack);
t_stack	*stack_create_indexed(t_stack *stack);
int		stack_is_sorted(t_stack *stack);

// stack_operations.c
int stack_swap(t_stack *stack);
int stack_push(t_stack *src, t_stack *dest);
int stack_rotate(t_stack *stack);
int stack_rotate_reverse(t_stack *stack);

// stack_operations_utils.c
t_list	*operation_create(char *operation);
void	operations_print_func(void *content);
void	operations_print(t_list *head);
void	operations_free(t_list *head);

// stack_operations_swap_push.c
void	stack_sa(t_stack *stack, t_list **head);
void	stack_sb(t_stack *stack, t_list **head);
void	stack_pa(t_stack *a, t_stack *b, t_list **head);
void	stack_pb(t_stack *a, t_stack *b, t_list **head);


// stack_operations_rotate.c
void	stack_ra(t_stack *stack, t_list **head);
void	stack_rb(t_stack *stack, t_list **head);
void	stack_rra(t_stack *stack, t_list **head);
void	stack_rrb(t_stack *stack, t_list **head);

// stack_operations_double.c
void	stack_ss(t_stack *a, t_stack *b, t_list **head);
void	stack_rr(t_stack *a, t_stack *b, t_list **head);
void	stack_rrr(t_stack *a, t_stack *b, t_list **head);

// Sort
t_list **stack_sort(t_stack *stack);
t_list **sort_basic(t_stack *stack);
t_list **sort_radix(t_stack *stack);
t_list **sort_3(t_stack *stack);

// Clean
void stack_clean_lst(t_list **head);

#endif